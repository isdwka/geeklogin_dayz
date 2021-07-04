class PlaneCrashMission extends SurvivorMissions
{
	//Mission related entities 
	Object CrashedC130;
	ItemBase MissionObject;

	//Mission parameters
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ContainerSpawns = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<vector> FireSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void PlaneCrashMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 700.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 8.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Енот";
	
		//Mission person names
		SurvivorName = "Тот-Кого-Нельзя-Называть";
		
		//Set mission messages
        m_MissionMessage1 = "Я только что принял экстренный вызов от военного лётчика. Один член экипажа заразился и внезапно напал на остальных. Он передал, что этот рейс имеет высший международный приоритет.";
        m_MissionMessage2 = "Также на борту находится "+ SurvivorName +", он агент ООН и, кажется, у него есть информация о лекарстве от COVID19 и ВИЧ. Они направлялись в Уэльс и были на высоте 30.000 футов, когда обнаружили заражение.";
        m_MissionMessage3 = "Пилот сказал, что его укусили, и он пытался экстренно приземлиться где-нибудь в поле возле\n** "+ m_MissionLocation +", "+ m_MissionLocationDir +" **\nУзнай, получилось ли у них приземлиться. На борту найдёшь и кое-что для себя";		
		
		//Engine fire spawns 
		FireSpawns.Insert("5.15 -2.18 -4.63");		//engine
		FireSpawns.Insert("5.15 -2.18 -5");			//engine
		FireSpawns.Insert("5.15 0 0");			//fire trace
		FireSpawns.Insert("4.8 0 0.5");			//fire trace
		FireSpawns.Insert("5.3 0 1");			//fire trace
		FireSpawns.Insert("5.15 0 15");			//fire trace
		FireSpawns.Insert("5.15 0 25");			//fire trace
		//FireSpawns.Insert("5.15 0 30");			//fire trace
		//FireSpawns.Insert("5.15 0 45");			//fire trace
		//FireSpawns.Insert("5.15 0 55");			//fire trace
		
		//Container spawnpoints
		ContainerSpawns.Insert("0.87 -4.5 -2.5");
		ContainerSpawns.Insert("0.87 -4.47 -0.5");
		
		//Infected spawnpoints
		InfectedSpawns.Insert("-10.5186 0 25.0269");
		InfectedSpawns.Insert("24.9775 0 -10.4146");
		InfectedSpawns.Insert("-30.1726 0 -6.2729");
		InfectedSpawns.Insert("-20.9209 0 4.6636");
		InfectedSpawns.Insert("15.0283 0 -10.3276");
		InfectedSpawns.Insert("7.2461 0 30.5884");
		InfectedSpawns.Insert("-20.6855 0 5.9956");
		InfectedSpawns.Insert("40 0 20");
		InfectedSpawns.Insert("-20 0 -40");
		InfectedSpawns.Insert("-50 0 50");
		InfectedSpawns.Insert("35 0 40");
		InfectedSpawns.Insert("-41 0 -20");
		InfectedSpawns.Insert("-31 0 -40");
		InfectedSpawns.Insert("-42 0 -20");
		InfectedSpawns.Insert("-32 0 -40");
		InfectedSpawns.Insert("-43 0 -20");
		InfectedSpawns.Insert("-33 0 -40");
		InfectedSpawns.Insert("-44 0 -20");
		InfectedSpawns.Insert("-34 0 -40");
		InfectedSpawns.Insert("-45 0 -20");
		InfectedSpawns.Insert("-35 0 -40");
		InfectedSpawns.Insert("-46 0 -20");
		InfectedSpawns.Insert("-36 0 -40");
		InfectedSpawns.Insert("-47 0 -20");
		InfectedSpawns.Insert("-37 0 -40");
		InfectedSpawns.Insert("-48 0 -20");
		InfectedSpawns.Insert("-38 0 -40");
		InfectedSpawns.Insert("-49 0 -20");
		InfectedSpawns.Insert("-34 0 -20");
		InfectedSpawns.Insert("-24 0 -40");
		InfectedSpawns.Insert("-35 0 -20");
		InfectedSpawns.Insert("-25 0 -40");
		InfectedSpawns.Insert("-36 0 -20");
		InfectedSpawns.Insert("-26 0 -40");
		InfectedSpawns.Insert("-37 0 -20");
		
		
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
	
	void ~PlaneCrashMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );		
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
	
	void ExplodeWreck(int count)
	{
		for ( int n=0; n < count; n++)
		{
			Grenade_Base Explosives = Grenade_Base.Cast( GetGame().CreateObject( "M67Grenade",CrashedC130.ModelToWorld("5.15 -2.28 -4.63")));
			Explosives.ActivateImmediate();
		}

	}
	void SpawnObjects()
	{
		//Spawn crashed plane crashed C130 
		int PlaneOriConversion;
		string PlaneOrientation;
		
		PlaneOriConversion = m_MissionDescription[3].ToInt() - 180;
		if ( PlaneOriConversion < 0 ) PlaneOriConversion += 360;
		PlaneOrientation = PlaneOriConversion.ToString() +" 0 0";
		
		CrashedC130 = GetGame().CreateObject( "Land_Wreck_C130J", m_MissionPosition );
		CrashedC130.SetOrientation( PlaneOrientation.ToVector() );
		CrashedC130.PlaceOnSurface();
		m_MissionObjects.Insert( CrashedC130 );

		//Enginefire
		for (int s=0; s < FireSpawns.Count(); s++)
		{
			FireplaceBase Enginefire;
			
			if ( s > 1 )
			{
				vector posXZ = CrashedC130.ModelToWorld( FireSpawns.Get(s) );
				float x = posXZ[0];
				float z = posXZ[2];
				float y = GetGame().SurfaceY(x,z);
				vector Groundpos = {x,y,z};
				
				Enginefire = FireplaceBase.Cast( GetGame().CreateObject( "Fireplace", Groundpos));
				Enginefire.SetPosition( Groundpos - "0 0.3 0" );
			}
			else 
			Enginefire = FireplaceBase.Cast( GetGame().CreateObject( "Fireplace", CrashedC130.ModelToWorld( FireSpawns.Get(s) )));
			
			Enginefire.Synchronize();
			Enginefire.GetInventory().CreateAttachment("Firewood");
			Enginefire.GetInventory().CreateAttachment("WoodenStick");
			Enginefire.GetInventory().CreateAttachment("Rag");
			Enginefire.StartFire( true );
			m_MissionObjects.Insert( Enginefire );
		}
		
		//Create smoke on destroyed engine
		Object EngineSmoke = GetGame().CreateObject( "Wreck_UH1Y", CrashedC130.ModelToWorld("5.15 -7 -3.63"),false,false,true);
		m_MissionObjects.Insert( EngineSmoke );
		
		//Explosion at planecrash time delayed	
		//ExplodeWreck(3);
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.ExplodeWreck, 800, false, 6 );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.ExplodeWreck, 1400, false, 5 );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.ExplodeWreck, 1800, false, 6 );
		
		//Spawn containers 
		int selectedLoadout;
		
		for (int i=0; i < ContainerSpawns.Count(); i++)
		{	
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "WoodenCrate", CrashedC130.ModelToWorld( ContainerSpawns.Get(i))));
			
			//Get random loadout 
			selectedLoadout = Math.RandomIntInclusive(0,8);	//!change randomization limit after adding new loadouts!	
		
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
				MissionObject.GetInventory().CreateInInventory("NailBox");
				MissionObject.GetInventory().CreateInInventory("NailBox");
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
			MissionObject.GetInventory().CreateInInventory("NailBox");
			MissionObject.GetInventory().CreateInInventory("NailBox");
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
			MissionObject.GetInventory().CreateInInventory("NailBox");
			MissionObject.GetInventory().CreateInInventory("NailBox");
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
			MissionObject.GetInventory().CreateInInventory("NailBox");
			MissionObject.GetInventory().CreateInInventory("NailBox");
		}
					
			Print("[SMM] Mission rewards spawned in reward container"+i+". Randomly selected loadout was "+selectedLoadout+"." );
				
			//Insert mission container into mission objects list
			m_MissionObjects.Insert( MissionObject );
		}
							
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}
	
	void SpawnAIs()
	{	
		//Spawn infected pilot
		vector InfectedPos = CrashedC130.ModelToWorld( "3 0 -9" );
		m_MissionAIs.Insert( GetGame().CreateObject( "ZmbM_CommercialPilotOld_Olive" , InfectedPos , false , true ) );
		DayZInfected InfectedSurvivor = DayZInfected.Cast( m_MissionAIs[0] );
			InfectedSurvivor.GetInventory().CreateAttachment("ZSh3PilotHelmet_Green");
			InfectedSurvivor.GetInventory().CreateAttachment("UKAssVest_Olive");
			InfectedSurvivor.GetInventory().CreateInInventory("Glock19");
			InfectedSurvivor.GetInventory().CreateInInventory("Mag_Glock_15Rnd");
			InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
			InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
			InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
					
			InfectedSurvivor.SetHealth("","",15);
		
		
		//Spawn infected
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos1 = CrashedC130.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos1, false, true ) );
		}	
	}
	
	void ObjDespawn() 
	{	
		//Despawn nothing
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone	
		//Respawn some infected 
		for ( int m = 0 ; m < InfectedSpawns.Count() ; m++)
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = CrashedC130.ModelToWorld( InfectedSpawns.Get(m) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));			
		}

		//Finish mission
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;			
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//nothing to check
	}
		
	void UpdateBots(float dt)
	{
		//no bots involved in this mission		
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

