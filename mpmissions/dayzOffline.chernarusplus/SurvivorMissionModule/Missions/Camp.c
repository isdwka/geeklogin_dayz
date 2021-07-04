class CampMission extends SurvivorMissions
{
	//Mission related entities 
	TentBase MissionObject;
	FireplaceBase MissionCampfire;
	Object cc_fireplace;
	Object cc_mtent;
	Grenade_Base BoobyTrap; 
	
	//Mission parameters
	int MsgDlyFinish = 300;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void CampMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 170.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Енот";
	
		//Mission person names
		TStringArray SurvivorNames = {"Юрий","Михаил","Борис","Валерий","Анатолий","Иван","Алексей","Дмитрий","Сергей","Николай"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages
        m_MissionMessage1 = "Мой друг "+ SurvivorName +" уже второй час не отвечает. Он отличный профи, если речь идёт о выживании на открытой местности. И я волнуюсь.";
        m_MissionMessage2 = "Где-то 5 часов назад, он сообщил мне, что нашёл кое-что в домах в "+ m_MissionLocation +". На обратном пути на него напали, однако даже не поцарапали.";
        m_MissionMessage3 = "Мне кажется, он говорил мне, что разбил свой лагерь рядом с \n "+ m_MissionLocation +", "+ m_MissionLocationDir +" \nЯ беспокоюсь. Загляни к нему, но будь осторожен, там много ловушек!";		
				
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
	
	void ~CampMission()
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
					if ( m_MissionObjects.Get(i).GetType() == "ClutterCutterFireplace" )
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
		//Clean up place from droped items before new tent spawns 
		bool ItemsAtGround = false; 
		
		GetGame().GetObjectsAtPosition( m_MissionPosition , 4.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.IsItemBase() )
			{
				ItemsAtGround = true;
				Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");				
				GetGame().ObjectDelete( FoundObject );
			}
		}
		//...and in case move tent pos a bit
		if ( ItemsAtGround )
		{
			float x = Math.RandomFloatInclusive( 1.5 , 3.0 );
			float y = Math.RandomFloatInclusive( 1.5 , 3.0 );
			int Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice > 4 ) x *= -1.0;
			Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice < 5 ) y *= -1.0;
			vector NewPosVector = { x, 0, y };
			m_MissionPosition += NewPosVector;
			Print("[SMM] BeforeSpawnCleanUp :: Items on the ground detected. Tent position predictively was moved a bit.");
		}
		
		//Spawn & pitch tent		
		MissionObject = TentBase.Cast( GetGame().CreateObject( "MediumTent", m_MissionPosition ) );
		MissionObject.Pitch( true , true );
		MissionObject.PlaceOnSurface();
		
		//Get random loadout 
		int selectedLoadout = Math.RandomIntInclusive(0,8);	//!change randomization limit after adding new loadouts!	

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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto31");
				
				
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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto32");
				
				
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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto33");
				
				
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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto34");
				
				
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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto35");
				
				
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
				MissionObject.GetInventory().CreateInInventory("ItemPhoto36");
				
				
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
			MissionObject.GetInventory().CreateInInventory("ItemPhoto37");		
			
				
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
			MissionObject.GetInventory().CreateInInventory("ItemPhoto39");
			
				
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
			MissionObject.GetInventory().CreateInInventory("ItemPhoto40");
			
				
		}
			
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was "+selectedLoadout+"." );
				
		//Insert mission tent into mission objects list
		m_MissionObjects.Insert( MissionObject );
	
		//Clutter Cutter Tent 	
		cc_mtent = GetGame().CreateObject( "MediumTentClutterCutter" , MissionObject.GetPosition() , false );
		cc_mtent.SetOrientation( MissionObject.GetOrientation() );
		GetGame().RemoteObjectCreate( cc_mtent );		 
		m_MissionObjects.Insert( cc_mtent );
		
		//Fireplace
		vector CampfirePosition;
		vector CampfireOrientation;
		vector CampFireDir = MissionObject.GetOrientation();
		float CampFireDist = 4;
			
		GetGame().ObjectDelete( cc_fireplace );
		GetGame().ObjectDelete( MissionCampfire );
		if ( CampFireDir[0] < 0 )	CampFireDir[0] = 360 + CampFireDir[0];
		//some nostalgic code 
		CampfirePosition [0] = m_MissionPosition [0] - Math.Sin( CampFireDir[0] * Math.DEG2RAD ) * CampFireDist;		//x offset
		CampfirePosition [2] = m_MissionPosition [2] - Math.Cos( CampFireDir[0] * Math.DEG2RAD ) * CampFireDist;		//y offset
		MissionCampfire = FireplaceBase.Cast( GetGame().CreateObject( "Fireplace", CampfirePosition ) );
		CampfireOrientation = MissionCampfire.GetOrientation();
		MissionCampfire.Synchronize();
		MissionCampfire.GetInventory().CreateAttachment("Firewood");
		MissionCampfire.GetInventory().CreateAttachment("WoodenStick");
		MissionCampfire.GetInventory().CreateAttachment("Rag");
		MissionCampfire.GetInventory().CreateAttachment("Stone");
		MissionCampfire.StartFire( true );
		m_MissionObjects.Insert( MissionCampfire );
		
		//Cluttercutter fireplace
		cc_fireplace = GetGame().CreateObject( "ClutterCutterFireplace" , MissionCampfire.GetPosition() );
		cc_fireplace.SetOrientation( CampfireOrientation );
		GetGame().RemoteObjectCreate( cc_fireplace );
		m_MissionObjects.Insert( cc_fireplace );
							
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}
	
	void SpawnAIs()
	{	
		//Spawn dead infected
		vector InfectedPos = MissionObject.ModelToWorld( "0 0 -6" );
		m_MissionAIs.Insert( GetGame().CreateObject( "ZmbM_HikerSkinny_Blue" , InfectedPos , false , true ) );
		DayZInfected InfectedSurvivor = DayZInfected.Cast( m_MissionAIs[0] );
			InfectedSurvivor.GetInventory().CreateAttachment("FlatCap_Blue");
			InfectedSurvivor.GetInventory().CreateAttachment("MountainBag_Blue");
			InfectedSurvivor.GetInventory().CreateAttachment("UKAssVest_Black");
		EntityAI weapon1 = InfectedSurvivor.GetInventory().CreateInInventory("M4A1_Green");
				weapon1.GetInventory().CreateAttachment("M4_RISHndgrd_Green");
				weapon1.GetInventory().CreateAttachment("M4_MPBttstck");
				weapon1.GetInventory().CreateAttachment("ACOGOptic");
				weapon1.GetInventory().CreateAttachment("M4_Suppressor");
			InfectedSurvivor.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			InfectedSurvivor.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			InfectedSurvivor.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			InfectedSurvivor.GetInventory().CreateInInventory("Ammo_556x45");
			InfectedSurvivor.GetInventory().CreateInInventory("Ammo_556x45");
			InfectedSurvivor.GetInventory().CreateInInventory("CanOpener");
			InfectedSurvivor.GetInventory().CreateInInventory("PeachesCan");
			InfectedSurvivor.GetInventory().CreateInInventory("Canteen");
			InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
				
			InfectedSurvivor.SetHealth("","",0);
		
		//Spawn boobytraped infected
		string RandomInfected = InfectedTypes.GetRandomElement();
		vector InfectedPos1 = MissionObject.ModelToWorld( "0 0 5" );
		
		m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos1, false, true ) );
		BoobyTrap = Grenade_Base.Cast( GetGame().CreateObject( "M67Grenade" , InfectedPos1, false, false, false ));
		BoobyTrap.ActivateImmediate();
		
		
		//Spawn infected
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	RandomInfected = InfectedTypes.GetRandomElement();
			InfectedPos1 = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos1, false, true ) );
		}	
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			//Exception: Fireplace & ClutterCutterFireplace will remain
			if ( m_MissionObjects.Get(i).GetType() == "Fireplace" || m_MissionObjects.Get(i).GetType() == "ClutterCutterFireplace" )	
			{
				Print("[SMM] "+ m_MissionObjects.Get(i).GetType() +" was excluded from pre-deletion.");
				continue;
			}
			
			//Delete Object clientside first
			if ( m_MissionObjects.Get(i).GetType() == "MediumTentClutterCutter" ) GetGame().RemoteObjectDelete( m_MissionObjects.Get(i) );
			
			//Delete Object serverside
			GetGame().ObjectDelete( m_MissionObjects.Get(i) );
		}
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone	
		//Respawn some infected 
		for ( int j = 0 ; j < 2 ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.GetRandomElement() );
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
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "MediumTent" ) 
			{
				if ( TentBase.Cast( m_MissionObjects[0] ).CanBeManipulated() && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission tent was packed by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}	
	}
		
	void UpdateBots(float dt)
	{
		//Test1.OnUpdate(dt);		
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
			Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
			return false;
		}
	}
}

