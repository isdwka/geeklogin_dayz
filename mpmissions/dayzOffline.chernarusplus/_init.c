#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\spawn_buildings.c"
#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\spawn_buildings_w.c"

void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 10, reset_day = 1;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
	
	//SpawnGl63Trade();
	SpawnGlBanking();
	SpawnGlNorthTrade();
	SpawnGlZzzWall();
	SpawnGlZzzKpp();
	SpawnGlNewTrade();
	SpawnGlClosedMilitary();
	SpawnGlParking();
	SpawnGlWestTrade();
	SpawnGlKrasnostav();
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		
		itemClothing = player.GetInventory().CreateInInventory("MSFC_Facemask_Black");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_ZSh12M_Black");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_Ballistic_Goggles_Black");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_BlackCamoGloves");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_BlackCamoBoots");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_JPC_Vest_Black");
		//itemClothing = player.GetInventory().CreateInInventory("MSFC_BlackCamoPlatePouches");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_BlackCamoPants");
		itemClothing = player.GetInventory().CreateInInventory("MSFC_BlackCamoJacket");

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Armband_Orange" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 8 );
				
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Armband_Blue" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 9 );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Glock19" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 1 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Mag_Glock_15Rnd" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Mag_Glock_15Rnd" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 4 );
				player.SetQuickBarEntityShortcut( itemEnt, 5 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Epinephrine" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 6 );

			SetRandomHealth( itemEnt );
			

			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.45 ) {
				itemEnt = player.GetInventory().CreateInInventory( "Hell_AlphaAK" );
					player.SetQuickBarEntityShortcut( itemEnt, 0 );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_AK74_30Rnd_Black" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_AK74_30Rnd_Black" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_AK74_30Rnd_Black" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_AK74_30Rnd_Black" );
				if ( rand < 0.15 ) {
					itemEnt = player.GetInventory().CreateInInventory( "AD_RMR_LM" );
					itemEnt = player.GetInventory().CreateInInventory( "M18SmokeGrenade_White" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
				}
				else if ( rand > 0.25 ) {
					itemEnt = player.GetInventory().CreateInInventory( "M68Optic" );
					itemEnt = player.GetInventory().CreateInInventory( "FlashGrenade" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
				}
				else {
					itemEnt = player.GetInventory().CreateInInventory( "Hell_HAMR_Optic" );
					itemEnt = player.GetInventory().CreateInInventory( "RGD5Grenade" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
					itemEnt = player.GetInventory().CreateInInventory( "MoneyRuble100" );
				}
			}
			
			else if ( rand > 0.55 ) {
				itemEnt = player.GetInventory().CreateInInventory( "Hell_M16A1" );
					player.SetQuickBarEntityShortcut( itemEnt, 0 );
				itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_M16A1_20Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_M16A1_20Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_M16A1_20Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_M16A1_20Rnd" );
				if ( rand < 0.65 ) {
					itemEnt = player.GetInventory().CreateInInventory( "FlashGrenade" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
				}
				else if ( rand > 0.80 ) {
					itemEnt = player.GetInventory().CreateInInventory( "M18SmokeGrenade_White" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
				}
				else {
					itemEnt = player.GetInventory().CreateInInventory( "RGD5Grenade" );
						player.SetQuickBarEntityShortcut( itemEnt, 3 );
					itemEnt = player.GetInventory().CreateInInventory( "MoneyRuble100" );
				}
			}
			
			else {
				if ( rand < 0.48 ) {
					itemEnt = player.GetInventory().CreateInInventory( "FAL" );
						player.SetQuickBarEntityShortcut( itemEnt, 0 );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_FAL_20Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_FAL_20Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_FAL_20Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Fal_FoldingBttstck" );
					itemEnt = player.GetInventory().CreateInInventory( "MoneyRuble100" );
				}
				else if ( rand > 0.52 ) {
					itemEnt = player.GetInventory().CreateInInventory( "Hell_HoneyBadger_BattleScars" );
						player.SetQuickBarEntityShortcut( itemEnt, 0 );
					itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_HoneyBadger_BattleScars_30Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_HoneyBadger_BattleScars_30Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Hell_Mag_HoneyBadger_BattleScars_30Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "MoneyRuble100" );
				}
				else {
					itemEnt = player.GetInventory().CreateInInventory( "MSFC_SVD_Wooden" );
						player.SetQuickBarEntityShortcut( itemEnt, 0 );
					itemEnt = player.GetInventory().CreateInInventory( "PSO1Optic" );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
					itemEnt = player.GetInventory().CreateInInventory( "MoneyRuble100" );
				}
			}

			SetRandomHealth( itemEnt );
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "CombatKnife" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 2 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "WaterBottle" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1000 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "PowderedMilk" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 200 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Battery9V" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 4 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Epinephrine" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );

			SetRandomHealth( itemEnt );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Morphine" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 1 );
				player.SetQuickBarEntityShortcut( itemEnt, 7 );

			SetRandomHealth( itemEnt );
			
				
			}
			
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}