/*
 * AttachmentImplementation.cpp
 *
 *  Created on: Mar 10, 2011
 *      Author: polonel
 */

#include "server/zone/objects/tangible/attachment/Attachment.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/loot/LootManager.h"

void AttachmentImplementation::initializeTransientMembers() {
	TangibleObjectImplementation::initializeTransientMembers();

	setLoggingName("AttachmentObject");

}

void AttachmentImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	int level = values->getMaxValue("creatureLevel");

	//Mods can't be lower than -1 or greater than 25
	int max = MAX(-1, MIN(25, round(0.1f * level + 3)));
	int min = MAX(-1, MIN(25, round(0.075f * level - 1)));

	int mod = System::random(max - min) + min;

	if(mod == 0)
		mod = 1;

	String modName = server->getZoneServer()->getLootManager()->getRandomLootableMod(gameObjectType);

	skillModMap.put(modName, mod);
}

void AttachmentImplementation::initializeMembers() {
	if (gameObjectType == SceneObjectType::CLOTHINGATTACHMENT) {
		setOptionsBitmask(32, true);
		attachmentType = CLOTHINGTYPE;

	} else if (gameObjectType == SceneObjectType::ARMORATTACHMENT) {
		setOptionsBitmask(32, true);
		attachmentType = ARMORTYPE;

	}

}

void AttachmentImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(msg, object);

	StringBuffer name;

	HashTableIterator<String, int> iterator = skillModMap.iterator();

	String key = "";
	int value = 0;

	for(int i = 0; i < skillModMap.size(); ++i) {

		iterator.getNextKeyAndValue(key, value);

		name << "cat_skill_mod_bonus.@stat_n:" << key;

		msg->insertAttribute(name.toString(), value);

		name.deleteAll();
	}

}
