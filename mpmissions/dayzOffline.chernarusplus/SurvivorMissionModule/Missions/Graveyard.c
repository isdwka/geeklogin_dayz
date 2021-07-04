class GraveyardMission extends SurvivorMissions
{
	//Mission related entities 
	ItemBase MissionObject;
	UndergroundStash stash;
	
	//Mission parameters
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void GraveyardMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 3600;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 200.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 2.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Енот";
	
		//Mission person names
		TStringArray SurvivorNames = {"Стонов", "Алексеев", "Казаков", "Степанов", "Иванов", "Миронов", "Антонов", "Юоьев", "Сорокин"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages
		m_MissionMessage1 = "Я только что получил сообщение, что командир отряда обороны Черноруссии "+ SurvivorName +" погиб.";
		m_MissionMessage2 = "Он был одним из самых великих людей на этой проклятой земле, "+ SurvivorName +" рассказывал, что последний раз он держал оборону в "+ m_MissionLocation +" и спрятал там кое-какое снаряжение.";
		m_MissionMessage3 = "Тайник закопан на кладбище\n** "+ m_MissionLocation +", "+ m_MissionLocationDir +", рядом с церковью. Думаю стоит кому-то сходить туда и найти его вещи, они могут сослужить хорошую службу кому-то ещё!";
		
		//Infected spawnpoints
		InfectedSpawns.Insert("-10.5186 0 25.0269");
		InfectedSpawns.Insert("24.9775 0 -10.4146");
		InfectedSpawns.Insert("-30.1726 0 -6.2729");
		InfectedSpawns.Insert("-20.9209 0 4.6636");
		InfectedSpawns.Insert("15.0283 0 -10.3276");
		InfectedSpawns.Insert("7.2461 0 30.5884");
		InfectedSpawns.Insert("-20.6855 0 5.9956");
		InfectedSpawns.Insert("-35 0 -20");
		InfectedSpawns.Insert("-25 0 -40");
		InfectedSpawns.Insert("-36 0 -20");
		InfectedSpawns.Insert("-26 0 -40");
		InfectedSpawns.Insert("-37 0 -20");
		InfectedSpawns.Insert("-35 0 -20");
		InfectedSpawns.Insert("-25 0 -40");
		InfectedSpawns.Insert("-36 0 -20");
		
		//Infected types
		//Male												//Female
		InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");	InfectedTypes.Insert("ZmbF_JournalistNormal_White");
		InfectedTypes.Insert("ZmbM_priestPopSkinny");		InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
		InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");	InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Red");		InfectedTypes.Insert("ZmbF_CitizenBSkinny");
		InfectedTypes.Insert("ZmbM_FishermanOld_Green");	InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
		InfectedTypes.Insert("ZmbM_HunterOld_Autumn");		InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");		InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
		InfectedTypes.Insert("ZmbM_MotobikerFat_Black");	InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");		InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");	InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
		InfectedTypes.Insert("ZmbM_HandymanNormal_Green");	InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
		InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");	InfectedTypes.Insert("ZmbF_PatientOld");
		InfectedTypes.Insert("ZmbM_Jacket_black");			InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
		InfectedTypes.Insert("ZmbM_Jacket_stripes");		InfectedTypes.Insert("ZmbF_VillagerOld_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");	InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
		InfectedTypes.Insert("ZmbM_PolicemanFat");			InfectedTypes.Insert("ZmbF_VillagerOld_Green");
		InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");	InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");		InfectedTypes.Insert("ZmbF_NurseFat");
		InfectedTypes.Insert("ZmbM_VillagerOld_White");		InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
		InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");		InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");	InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
		InfectedTypes.Insert("ZmbM_DoctorFat");				InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
		InfectedTypes.Insert("ZmbM_PatientSkinny");			InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
		InfectedTypes.Insert("ZmbM_ClerkFat_Brown");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
		InfectedTypes.Insert("ZmbM_ClerkFat_White");		InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
		InfectedTypes.Insert("ZmbM_Jacket_magenta");		InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
		InfectedTypes.Insert("ZmbM_PolicemanSpecForce");	InfectedTypes.Insert("ZmbF_DoctorSkinny");	
		InfectedTypes.Insert("MSFC_Zombie_FromLaba01");		InfectedTypes.Insert("MSFC_Zombie_FromLaba02");
		InfectedTypes.Insert("MSFC_Zombie_FromLaba03");		InfectedTypes.Insert("MSFC_Zombie_FromLaba04");		
	}
	
	void ~GraveyardMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else 
				{
					//Delete Object clientside first
					if ( m_MissionObjects.Get(i).GetType() == "ClutterCutter2x2" )
					GetGame().RemoteObjectDelete( m_MissionObjects.Get(i) );
					
					//Delete Object serverside	
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );		
				}
			}
			m_MissionObjects.Clear();
		}
		
		//Despawn mission AI's
		if ( m_MissionAIs )
		{
			if ( m_MissionAIs.Count() > 0 )
			{
				Print("[SMM] Despawning "+ m_MissionAIs.Count() +" mission AI's from old mission...");
				for ( int k = 0; k < m_MissionAIs.Count(); k++ )
				{
					GetGame().ObjectDelete( m_MissionAIs.Get(k) );
				}
				m_MissionAIs.Clear();			
			}
			else Print("[SMM] No mission AI's to despawn.");
		}
		
		//Delete PlayersInZone list & reset container takeaway
		if ( m_PlayersInZone )	m_PlayersInZone.Clear();
		if ( m_ContainerWasTaken ) m_ContainerWasTaken = false;			
	}	
	
	void SpawnObjects()
	{	
		
		//Create underground stash  
		stash = UndergroundStash.Cast( GetGame().CreateObject( "UndergroundStash", m_MissionPosition ));
		stash.PlaceOnGround(); 
		Print(" Orientation UndergroundStash : "+ stash.GetOrientation().ToString() );
		vector pos = stash.GetPosition();
		vector ori = stash.GetOrientation();
		
		if ( ori[2] == -180 || ori[2] == 180 )
		{	//Bugfix for invisible Undergroundstashes
			ori[2] = 0;
			stash.SetOrientation( ori );
		}
				
		//Spawn seachest in stash
		MissionObject = ItemBase.Cast( stash.GetInventory().CreateInInventory("SeaChest"));		
		
		//Get random loadout 
		int selectedLoadout = Math.RandomIntInclusive( 0, 8);	//!change randomization limit after adding new loadouts!	

		//Spawn selected loadout items in mission object
		EntityAI weapon;
				
		if (selectedLoadout == 0)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("MSFC_RPK16MR_Green");
				weapon.GetInventory().CreateAttachment("ACOGOptic");
				weapon.GetInventory().CreateAttachment("AK_Suppressor");
				MissionObject.GetInventory().CreateInInventory("MSFC_Handguard_RPK16MR_Green");
				MissionObject.GetInventory().CreateInInventory("MSFC_Handguard_RPK16MR_Green");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto21");
				
				
			}
			if (selectedLoadout == 1)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("SVD");
					weapon.GetInventory().CreateAttachment("PSO1Optic");
					weapon.GetInventory().CreateAttachment("AK_Suppressor");
				MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
				MissionObject.GetInventory().CreateInInventory("Rangefinder");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd");
				MissionObject.GetInventory().CreateInInventory("GhillieSuit_Woodland");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto22");
				
				
			}
			if (selectedLoadout == 2)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("ASVAL");
					weapon.GetInventory().CreateAttachment("ACOGOptic");
				MissionObject.GetInventory().CreateInInventory("Mag_VAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_VAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_VAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_VAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39AP_20Rnd");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto23");
				
				
			}
			if (selectedLoadout == 3)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("FAL");
					weapon.GetInventory().CreateAttachment("Fal_OeBttstck");
					weapon.GetInventory().CreateAttachment("ACOGOptic");
				MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_308Win_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_308Win_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_308Win_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_308Win_20Rnd");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto24");
				
				
			}	
			if (selectedLoadout == 4)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("Hell_HoneyBadger_BattleScars");
				MissionObject.GetInventory().CreateInInventory("Hell_Mag_HoneyBadger_BattleScars_30Rnd");
				MissionObject.GetInventory().CreateInInventory("Hell_Mag_HoneyBadger_BattleScars_30Rnd");
				MissionObject.GetInventory().CreateInInventory("Hell_Mag_HoneyBadger_BattleScars_30Rnd");
				MissionObject.GetInventory().CreateInInventory("Hell_Mag_HoneyBadger_BattleScars_30Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_300AAC_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_300AAC_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_300AAC_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_300AAC_20Rnd");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto25");
				
				
			}	
			if (selectedLoadout == 5)
			{
				weapon = MissionObject.GetInventory().CreateInInventory("Hell_AlphaAK");
				MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");
				MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");
				MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");
				MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
				MissionObject.GetInventory().CreateInInventory("ItemPhoto26");
				
				
			}
		if (selectedLoadout == 6)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("Hell_MPX");
				weapon.GetInventory().CreateAttachment("M68Optic");
				weapon.GetInventory().CreateAttachment("PistolSuppressor");			
			MissionObject.GetInventory().CreateInInventory("Hell_Mag_MPX_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Hell_Mag_MPX_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Hell_Mag_MPX_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Hell_Mag_MPX_30Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");	
			MissionObject.GetInventory().CreateInInventory("ItemPhoto27");	
			
				
		}
		if (selectedLoadout == 7)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("Deagle_Gold");
				weapon.GetInventory().CreateAttachment("PistolOptic");
				weapon.GetInventory().CreateAttachment("PistolSuppressor");
			MissionObject.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_357_20Rnd");
			MissionObject.GetInventory().CreateInInventory("ItemPhoto29");
			
				
		}
		if (selectedLoadout == 8)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("Saiga");
			MissionObject.GetInventory().CreateInInventory("Mag_Saiga_Drum20Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_Saiga_Drum20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_12gaSlug_10Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_12gaSlug_10Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
			MissionObject.GetInventory().CreateInInventory("ItemPhoto30");
			
				
		}
			
		//Clutter cutter stash 	
		Object cc_stash = GetGame().CreateObject( "ClutterCutter2x2" , MissionObject.GetPosition() );
		GetGame().RemoteObjectCreate( cc_stash );		
		
		//Insert mission objects into mission objects list
		m_MissionObjects.Insert( MissionObject );
		m_MissionObjects.Insert( stash );		 
		m_MissionObjects.Insert( cc_stash );			
		
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was "+selectedLoadout+"." );						
	}
	
	void SpawnAIs()
	{
		//Spawn infected
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );
		}		
	}

	void ObjDespawn() 
	{	
		//Despawn nothing
	}
				
	void MissionFinal()
	{	//When player enters last mission target zone
		//Respawn some infected 
		for ( int j = 0 ; j < 3 ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );			
		}

		//Finish mission
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;			
	}
		
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "SeaChest" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] )) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}		
	}
		
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		if ( m_MissionPosition && m_MissionPosition != "0 0 0" )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;
		}
		else 
		{
			Print("[SMM] Mission position was rejected or doesn't exist!");
			return false;
		}					
	}	
}