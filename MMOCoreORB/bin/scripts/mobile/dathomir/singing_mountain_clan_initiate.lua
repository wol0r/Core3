singing_mountain_clan_initiate = Creature:new {
	objectName = "@mob/creature_names:singing_mtn_clan_initiate",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "mtn_clan",
	faction = "mtn_clan",
	level = 50,
	chanceHit = 0.5,
	damageMin = 395,
	damageMax = 500,
	baseXp = 4916,
	baseHAM = 10000,
	baseHAMmax = 12000,
	armor = 1,
	resists = {30,30,75,-1,75,-1,-1,35,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_dathomir_sing_mt_clan_initiate.iff"},
	lootGroups = {
		{
			groups = {
				{group = "smc_rare", chance = 1000000},
				{group = "crystals_okay", chance = 500000},
				{group = "color_crystals", chance = 500000},
				{group = "armor_attachments", chance = 450000},
				{group = "clothing_attachments", chance = 450000},
				{group = "melee_weapons", chance = 1025000},
				{group = "rifles", chance = 1025000},
				{group = "pistols", chance = 1025000},
				{group = "carbines", chance = 1025000},
				{group = "smc_clothing", chance = 3000000}
			},
			lootChance = 7000000
		}			
	},
	weapons = {"mixed_force_weapons"},
	conversationTemplate = "",
	attacks = merge(brawlermaster,pikemanmaster)
}

CreatureTemplates:addCreatureTemplate(singing_mountain_clan_initiate, "singing_mountain_clan_initiate")
