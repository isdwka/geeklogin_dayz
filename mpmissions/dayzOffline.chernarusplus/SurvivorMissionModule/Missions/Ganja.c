class GanjaMission extends SurvivorMissions
{
	//Mission related entities 
	Car MissionCar;
	Object MissionBuilding;
	ItemBase MissionObject;
	
	//Mission parameters
	int ReqWeedAmount = 25;					//pieces, mission ganja (equivalent to x * 4 gramms)
	int ExtendedTimout = 1500;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> GarageCarSpawns = new array<vector>;
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> PriInfectSpawns = new array<vector>;
	ref array<vector> SecInfectSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	
	//Mission variables 
	string SurvivorName;	
	
	bool IsExtended() return true;
	
	void GanjaMission()
	{		
		//Select primary mission
		m_MissionExtended = true;
		
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, primary mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 150.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 2.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Енот";
	
		//Mission person names
		TStringArray SurvivorNames = {"Михаил","Борис","Максим","Иван","Грен","Димыч","Сербон","Колян"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		m_MissionMessage1 = SurvivorName +", парень, который работал на меня, рассказал мне, что он скрестил особый сорт конопли. Мне нужен этот сорт растения для эмм.. экспериментов с заражёнными. Ещё он рассказал, что удобрял его маленькими кусочками зомби";
		m_MissionMessage2 = "Я думаю, он имел в виду любой ферментированный напиток с водой, зараженной золой и кусочками мяса, приготовленный в кухонном миксере. Воздействие на рост и цветение растений было огромным. Также кажется, что оно содержит вещество, не похожее на природные каннабиноиды. Я хочу извлечь это вещество, чтобы посмотреть, как оно действует на инфицированных.";
		m_MissionMessage3 = SurvivorName +" спрятал свои травы в гараже в\n** "+ m_MissionLocation +" **\nОн наверняка запер двери гаража, поэтому попробуй использовать отмычку или начни работать головой.";
		
		//Spawnpoints for MissionCar in Garage 
		GarageCarSpawns.Insert("5.055 -1.504 -2.064"); 	//left garage
		GarageCarSpawns.Insert("-4.702 -1.504 -1.843");	//right garage
		
		//Spawnpoints for MissionObjects in middle garage (Do not change order!)
		Spawnpoints.Insert("1.575 -0.605 -5.431");  //on table right (3x motor oil)
		Spawnpoints.Insert("1.750 -0.605 -4.731");  //on table center (bag)
		Spawnpoints.Insert("1.800 -0.575 -3.8");	//on table left (weed pile)
		Spawnpoints.Insert("1.724 -1.504 -1.560");	//left beside table (gasoline canister)
		Spawnpoints.Insert("-1.85 -1.04 -2.196");	//shelf (spark plug)
		
		//Spawnpoint for reward container in Gas Station Building
		Spawnpoints.Insert("0.330 -1.538 0.6");		//beside desk
				
		//Infected spawnpoints for primary mission
		PriInfectSpawns.Insert("-10 0 20");
		PriInfectSpawns.Insert("-12 0 -30");
		PriInfectSpawns.Insert("20 0 -15");
		PriInfectSpawns.Insert("-30 0 -15");
		PriInfectSpawns.Insert("-16 0 -25");
		PriInfectSpawns.Insert("17 0 10");
		PriInfectSpawns.Insert("28 0 -30");
		
		//Infected spawnpoints for secondary mission 
		SecInfectSpawns.Insert("-11 0 -7");
		SecInfectSpawns.Insert("-8 0 8");
		SecInfectSpawns.Insert("8 0 -9");
		SecInfectSpawns.Insert("6 0 -5");
		SecInfectSpawns.Insert("18 0 15");
		
		//Infected types for secondary mission position
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
										
		//Search for mission building at primary mission position	
		GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_Garage_Row_Small" )
			{	
				MissionBuilding = FoundObject;			 
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				break;
			}	
		}
		if ( !MissionBuilding ) Print("[SMM] Garage couldn't be found. Mission rejected!");
		else
		{
			//Close all garage doors
			Building Garage = Building.Cast( MissionBuilding );
			for ( int j=0; j < 3; j++ ) 
			{
				if ( Garage.IsDoorOpen(j) ) Garage.CloseDoor(j);
				if ( !Garage.IsDoorLocked(j) ) Garage.LockDoor(j); 
			}	
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, Garage );		
		}			
	}
	
	void ~GanjaMission()
	{	
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{				
				if ( !m_MissionObjects.Get(i))	continue;
				else
				{	
					if ( m_MissionObjects.Get(i).IsTransport() ) 
					{
						//Don't delete just add full damage to MissionCar
						m_MissionObjects.Get(i).SetHealth("","",0);
						continue;
					}
							
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );
				}			
			}
			m_MissionObjects.Clear();
		}	
		
		//Delete mission AI's
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
	
	void SpawnCar()
	{		
		//Create MissionCar
		Print("[SMM] Spawning mission vehicle");
		
		MissionCar = Car.Cast(GetGame().CreateObject("OffroadHatchback", m_MissionPosition ));
		MissionCar.GetInventory().CreateAttachment("HatchbackWheel");
		MissionCar.GetInventory().CreateAttachment("HatchbackWheel");
		MissionCar.GetInventory().CreateAttachment("HatchbackWheel");
		MissionCar.GetInventory().CreateAttachment("HatchbackWheel");
		MissionCar.GetInventory().CreateAttachment("HatchbackWheel");
		MissionCar.GetInventory().CreateAttachment("HatchbackTrunk");
		MissionCar.GetInventory().CreateAttachment("HatchbackHood");
		MissionCar.GetInventory().CreateAttachment("HatchbackDoors_Driver");
		MissionCar.GetInventory().CreateAttachment("HatchbackDoors_CoDriver");
		MissionCar.GetInventory().CreateAttachment("CarRadiator");
		MissionCar.GetInventory().CreateAttachment("CarBattery");
		MissionCar.GetInventory().CreateAttachment("HeadlightH7");
		MissionCar.GetInventory().CreateAttachment("HeadlightH7");
		
		//Create car inventory
		MissionCar.GetInventory().CreateInInventory("Canteen");
		MissionCar.GetInventory().CreateInInventory("PersonalRadio");
		MissionCar.GetInventory().CreateInInventory("TireRepairKit");
		EntityAI kit = MissionCar.GetInventory().CreateInInventory("FirstAidKit");
			kit.GetInventory().CreateInInventory("TetracyclineAntibiotics");
			kit.GetInventory().CreateInInventory("BandageDressing");
			kit.GetInventory().CreateInInventory("Morphine");
		MissionCar.GetInventory().CreateInInventory("Battery9V");
		MissionCar.GetInventory().CreateInInventory("Battery9V");
		MissionCar.GetInventory().CreateInInventory("Battery9V");
		MissionCar.GetInventory().CreateInInventory("Battery9V");
		MissionCar.GetInventory().CreateInInventory("HeadlightH7");
		MissionCar.GetInventory().CreateInInventory("HeadlightH7");

		//Fill coolant with water
		MissionCar.Fill(CarFluid.COOLANT, 20.0 );
		
		//Set car orientation with rear to door 
		MissionCar.SetOrientation( MissionBuilding.GetOrientation() + "180 0 0" );
		
		//Set car CE lifetime
		MissionCar.SetLifetime( 3600 );	
		
		m_MissionObjects.InsertAt( MissionCar, 0 ); 		
	}
	
	void SpawnRewards()
	{		
		//new MissionObject after deleting protector case
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "MountainBag_Green", m_MissionPosition ));
		
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
	}
	
	void SpawnObjects()
	{	
		if ( m_MissionExtended )
		{	
			//Get random spawnpoint for car
			m_MissionPosition = MissionBuilding.ModelToWorld( GarageCarSpawns.GetRandomElement());
	 		
			//Clean up MissionCar spawnpoint
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.5, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					Object FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
			
			//Spawn car 1 second later			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnCar, 1000 );
						
			//Spawn Ganja bag
			MissionObject = ItemBase.Cast( GetGame().CreateObject("CourierBag", MissionBuilding.ModelToWorld( Spawnpoints.Get(1) )));
			m_MissionObjects.InsertAt( MissionObject, 1 );			
			
			//Spawn mission vehicle related stuff
			Object CarStuff;
			
			CarStuff = GetGame().CreateObject("EngineOil", MissionBuilding.ModelToWorld( Spawnpoints.Get(0) ));
			CarStuff.SetOrientation( MissionBuilding.GetOrientation() + "-90 0 0");
			m_MissionObjects.InsertAt( CarStuff, 2 );
			CarStuff = GetGame().CreateObject("EngineOil", MissionBuilding.ModelToWorld( Spawnpoints.Get(0) + "0.2 0 0" ));
			CarStuff.SetOrientation( MissionBuilding.GetOrientation() + "-90 0 0");
			m_MissionObjects.InsertAt( CarStuff, 3 );			
			CarStuff = GetGame().CreateObject("EngineOil", MissionBuilding.ModelToWorld( Spawnpoints.Get(0) + "0.4 0 0" ));
			CarStuff.SetOrientation( MissionBuilding.GetOrientation() + "-90 0 0");
			m_MissionObjects.InsertAt( CarStuff, 4 );			
			m_MissionObjects.Insert( GetGame().CreateObject("CanisterGasoline", MissionBuilding.ModelToWorld( Spawnpoints.Get(3) )));
			m_MissionObjects.Insert( GetGame().CreateObject("SparkPlug", MissionBuilding.ModelToWorld( Spawnpoints.Get(4) )));		
			m_MissionObjects.Insert( GetGame().CreateObject("Wrench", MissionBuilding.ModelToWorld( Spawnpoints.Get(4) - "0 0 0.2" )));
			
			//Cluster spawn mission ganja 			
			for ( int j=0; j < ReqWeedAmount; j++ )
			{
				Object Ganja = GetGame().CreateObject("Cannabis", MissionBuilding.ModelToWorld( Spawnpoints.Get(2) ));
				vector gpos = { Math.RandomFloatInclusive(-0.3, 0.3), 0, Math.RandomFloatInclusive(-0.3, 0.3) };
				Ganja.SetPosition( MissionBuilding.ModelToWorld( Spawnpoints.Get(2) + gpos ) );
				m_MissionObjects.Insert( Ganja );
			}
			
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...primary mission deployed!");
		}
		else
		{
			//Spawn nothing when player is entering secondary mission zone
				
			Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...secondary mission deployed!");
		}
	}
	
	void SpawnAIs()
	{	
		string RandomInfected;
		vector InfectedPos;
		DayZInfected Zed;
				
		if ( !MissionBuilding ) Print("[SMM] Extended Mission : Missionbuilding couldn't be found in "+ m_MissionDescription[3] +"." );		
		else
		{
			if ( m_MissionExtended )
			{
				//Spawn some infected at garage
				for ( int j = 0 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( PriInfectSpawns.Get(j) );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}
			}
			else
			{
				//Spawn some infected at Gas station
				for ( int k = 0 ; k < SecInfectSpawns.Count() ; k++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( SecInfectSpawns.Get(k) );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}		
			}
		}
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			//Exception: MissionCar will remain but gets damaged
			if ( m_MissionObjects.Get(i) && m_MissionObjects.Get(i).IsTransport() )	
			{
				m_MissionObjects.Get(i).SetHealth("","",0);
				continue;
			}
			
			//Delete Object
			GetGame().ObjectDelete( m_MissionObjects.Get(i) );
			m_MissionObjects.Remove(i);
		}
	}
	
	void ExtendMission()
	{	//When player enters mission target zone at primary mission
		
		//Set messages for secondary mission
		m_MissionMessage1 = "Отличная работа салага, ты нашёл машину "+ SurvivorName +"а. Вероятно он слил всё топливо, так что подготовь машину перед долгой поездкой. Проверь, есть ли где-нибудь в гаражах сушеный каннабис, возьми пакет и положи в него все 25 штук.";
		m_MissionMessage2 = "Наплавляйся в ** "+ m_MissionDescription[3] +" на заправку **\nтам оставь пакет с травой на столе рядом с кассой. "+ SurvivorName +"ова трава имеет высший приоритет! Не кради и не кури её самостоятельно, потому что это может быть очень опасно. Ибо я отстрелю твои яйца.";
		m_MissionMessage3 = "Награду заберёшь на заправке. Будь осторожен, на пути в "+ m_MissionDescription[3] +" тебя могут поджидать сильные твари. Надеюсь права ты не купил и водишь аккуратно. И помни, что курение - вредит вашему здоровью!";
		
		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout for secondary mission
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for secondary mission		
		m_MissionZoneOuterRadius = 80.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get secondary mission position
		if ( m_MissionDescription[3] == "Widok" )
		{
			if ( EventsWorldData.GetBuildingsAtLoc("Land_FuelStation_Build", m_MissionDescription[3], ExtendedPosList ))
			m_MissionPosition = ExtendedPosList.GetRandomElement();			
		}
		else if ( EventsWorldData.GetBuildingsAtLoc("Land_FuelStation_Build_Enoch", m_MissionDescription[3], ExtendedPosList ))
		m_MissionPosition = ExtendedPosList.GetRandomElement();
		else Print("[SMM] Can't get secondary MissionPosition in "+ m_MissionDescription[3] +" from EventsWorldData!");
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		//do nothing		
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if MissionObject is brought to MissionPosition 
		if ( MissionObject && MissionObject.ClassName() == "CourierBag" && !m_MissionExtended )
		{		
			float BagDistance = vector.Distance( MissionObject.GetPosition(), m_MissionPosition );
			if ( BagDistance < 3 )
			{
				int CargoCount = MissionObject.GetInventory().CountInventory();
				int LastCount = 0;
				int FoundObjects = 0;
				
				if ( CargoCount != LastCount )
				{
					if ( CargoCount >= ReqWeedAmount && FoundObjects <= ReqWeedAmount )
					{	
						CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
						
						for ( int i = 0; i < CargoCount; i++ )
						{
							EntityAI CargoItem = CargoItems1.GetItem(i);
							if ( m_MissionObjects.Find( CargoItem ) > -1 ) FoundObjects++;
							else continue;					
							
							//When requested amount of Ganja is present, despawn MissionObject & spawn rewards
							if ( FoundObjects >= ReqWeedAmount )
							{
								Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ ReqWeedAmount +" MissionObjects in the container.");
								//delete container first
								GetGame().ObjectDelete( MissionObject );
								//spawn rewards 
								SpawnRewards();
								m_RewardsSpawned = true;
								m_MsgNum = -1;
								m_MsgChkTime = m_MissionTime + MsgDlyFinish;
								break;
							} 
						}
						LastCount = CargoCount;
					}
				} 		
			}
		}		
	}
		
	void UpdateBots( float dt )
	{
		//No bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at secondary mission position
		if ( !m_MissionExtended )
		{			
			GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int i=0; i < m_ObjectList.Count(); i++ )
			{ 
				Object FoundObject = m_ObjectList.Get(i);
				if ( FoundObject.GetType() == "Land_FuelStation_Build_Enoch" || FoundObject.GetType() == "Land_FuelStation_Build")
				{			 
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is "+ m_MissionDescription[3] +" Gas Station @ "+ m_MissionPosition );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.Get(5) );
					break;
				}	
			}
		}
		
		if ( MissionBuilding )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : MissionBuilding can't be found!");
			if ( MissionSettings.DebugMode ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}
