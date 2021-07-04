class FreePigsMission extends SurvivorMissions
{
	//Mission related entities 
	Car MissionCar;
	Object MissionBuilding;
	ItemBase MissionObject;
	
	//Mission parameters
	int ReqMeatAmount = 14;					//pieces, mission ganja (equivalent to x * 4 gramms)
	int ExtendedTimout = 1500;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> PriInfectSpawns = new array<vector>;
	ref array<vector> SecInfectSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	ref array<vector> CagedPigSpawns = new array<vector>;
	
	//Mission variables 
	string SurvivorName;
	vector RewardsPosition = "0.84 -0.75 0.16";	
	vector TargetPosition = "-1.74 -3.01 0.49";
	
	bool IsExtended() return true;
	
	void FreePigsMission()
	{		
		//Select primary mission
		m_MissionExtended = true;
		
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, primary mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 150.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 6.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Енот";
	
		//Mission person names
		TStringArray SurvivorNames = {"Димон","Артём","Михаил","Борис","Санчес","Чехов","Иван","Мерлин","Максим","Сергон","Николаус","Владимир"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		m_MissionMessage1 = SurvivorName +", фермер из "+ m_MissionLocation +", умер 2 дня назад. Бандиты перерезали ему горло. Он защищал своих свинюшек от зомбей и рейдоров. Доставлял много мяса в лагерь выживших, где-то в лесах.";
		m_MissionMessage2 = "Его фирменные стейки, были самыми вкусными на районе. Его свиньи ещё в сарае. Боюсь, что они могут умереть с голоду, если они уже не умерли от заражения или не были ограблены бандитами.";
		m_MissionMessage3 = "Отправляйся на ферму "+ SurvivorName +"а. Она расположена по координатам\n** "+ m_MissionLocationDir +" в "+ m_MissionLocation +" **\nи освободи бедняшек. Дай им шанс на выживание. Тебе понадобится нож.";
		
		//Spawnpoints for caged pigs in farm (view from inside building at door position)
		//right cage row
		CagedPigSpawns.Insert("0.92 -3.01 3.10"); 
		CagedPigSpawns.Insert("-0.49 -3.01 3.10");
		CagedPigSpawns.Insert("-4.72 -3.01 3.10");
		CagedPigSpawns.Insert("-6.13 -3.01 3.10");
		//left cage row 
		CagedPigSpawns.Insert("-7.42 -3.01 -2.21");
		//next building part of shed left 
		CagedPigSpawns.Insert("7.78 -3.04 2.85");
		CagedPigSpawns.Insert("6.28 -3.04 2.85");
		
		//Spawnpoints for MissionObjects in middle garage (Do not change order!)
		Spawnpoints.Insert("0.249 -3.01 -3.24");  	//at left door to chicken room (Wellies)

		//Infected spawnpoints for primary mission
		PriInfectSpawns.Insert("-30 0 -10");
		PriInfectSpawns.Insert("-35 0 -13");
		PriInfectSpawns.Insert("-40 0 -9");
		PriInfectSpawns.Insert("-45 0 -15");
		PriInfectSpawns.Insert("-30 0 10");
		PriInfectSpawns.Insert("-35 0 13");
		PriInfectSpawns.Insert("-40 0 9");
		PriInfectSpawns.Insert("-45 0 15");
		
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
			if ( FoundObject.GetType() == "Land_Farm_CowshedA")
			{	
				MissionBuilding = FoundObject;			 
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				break;
			}	
		}
		if ( !MissionBuilding ) Print("[SMM] Farm couldn't be found. Mission rejected!");
		else
		{
			//Close all farm doors
			Building farm = Building.Cast( MissionBuilding );
			for ( int j=0; j < 5; j++ ) if ( farm.IsDoorOpen(j) ) farm.CloseDoor(j); 
	
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, farm );		
		}			
	}
	
	void ~FreePigsMission()
	{	
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{				
				if ( !m_MissionObjects.Get(i))	continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );			
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
	
	void SpawnRewards()
	{						
		//new MissionObject after deleting hunting bag
		MissionObject = ItemBase.Cast( GetGame().CreateObject("MountainBag_Green", m_MissionPosition ));
		MissionObject.SetPosition( m_MissionPosition );
		
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
					
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was "+selectedLoadout+"." );			
	}
	
	void SpawnObjects()
	{	
		if ( m_MissionExtended )
		{	
			//New MissionPosition is at first cages in farm building
			m_MissionPosition = MissionBuilding.ModelToWorld( TargetPosition );
			
			//Spawn farmer loot			
			m_MissionObjects.Insert( GetGame().CreateObject("Wellies_Green", MissionBuilding.ModelToWorld( Spawnpoints.Get(0) )));
		
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...primary mission deployed!");
		}
		else
		{
			//New MissionPosition is hiking rest table
			m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
			
			//Spawn mission target huntig bag
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "HuntingBag", m_MissionPosition ));
			MissionObject.SetPosition( m_MissionPosition );
			MissionObject.SetOrientation( MissionBuilding.GetOrientation() + "-90 -25 0" );
			m_MissionObjects.InsertAt( MissionObject, 0 );
				
			Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...secondary mission deployed!");
		}
	}
	
	void SpawnAIs()
	{	
		int PigPosCount;
		string RandomInfected;
		vector InfectedPos;
		vector PigPos;
		DayZInfected Zed;
		Object Pig;
		Object MissionBuilding2;
				
		if ( !MissionBuilding ) Print("[SMM] Extended Mission : Missionbuilding couldn't be found in "+ m_MissionDescription[3] +".");		
		else
		{
			if ( m_MissionExtended )
			{
				//Search for second farm building part 
				GetGame().GetObjectsAtPosition( MissionBuilding.ModelToWorld("-19.54 0 0"), 1.5, m_ObjectList, m_ObjectCargoList );				
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					Object FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.GetType() == "Land_Farm_CowshedB" )
					{
						Print("[SMM] Second farm building found.");
						MissionBuilding2 = FoundObject;
						PigPosCount = CagedPigSpawns.Count();
						break;
					}
				}
				
				if ( !MissionBuilding2 )
				{
					Print("[SMM] No second farm building found");
					PigPosCount = 5;
				}
				
				//Spawn caged pigs in farm
				for ( int j = 0 ; j < PigPosCount ; j++ )
				{
					if ( j < 5 )
					PigPos = MissionBuilding.ModelToWorld( CagedPigSpawns.Get(j) );		
					else PigPos = MissionBuilding2.ModelToWorld( CagedPigSpawns.Get(j) );
					
					Pig = GetGame().CreateObject( "Animal_SusDomesticus", PigPos, false, true );
					Pig.SetPosition( PigPos );
					m_MissionAIs.Insert( Pig );
				}	
				
				//Spawn a hen (stays on server til restart)
				GetGame().CreateObject( "Animal_GallusGallusDomesticus", MissionBuilding.ModelToWorld("6.8 -3.01 -5.76"), false, true );
			}
			else
			{
				//Spawn some infected at hiking rest
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
		//Despawn nothing	
	}
	
	void ExtendMission()
	{	//When player enters mission target zone at primary mission
		
		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout for secondary mission
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for secondary mission		
		m_MissionZoneOuterRadius = 120.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get secondary mission position
		if ( EventsWorldData.GetBuildingsAtLoc("Land_Misc_TrailRoof_Small", m_MissionDescription[3], ExtendedPosList ))
		m_MissionPosition = ExtendedPosList.GetRandomElement();
		else Print("[SMM] Can't get secondary MissionPosition in "+ m_MissionDescription[3] +" from EventsWorldData!");

		string Coords = Math.Round( m_MissionPosition[0] ).ToString() +" / "+ Math.Round( m_MissionPosition[2] ).ToString();  
		
		//Set messages for secondary mission,
		m_MissionMessage1 = "Отлично, ты нашёл свиней. Выпусти их, и защити от заражённых. Я сегодня ещё не ел, поэтому убей несколько особей, и разделай на мясо. Стреляй в голову, живодёр!";
		m_MissionMessage2 = "Мой человек придёт забрать мясо. Я оставил рюкзак на лавке у стола, что в лесу на туристической тропе. ";
		m_MissionMessage3 = "Найди это место со столом\n** "+ m_MissionDescription[3] +", по координатам: "+ Coords +" **\nИ положи не меньше "+ ReqMeatAmount +" свиных  стейков в сумку. Я очень голоден!";
				
		//Search for mission building at old mission position	
		GetGame().GetObjectsAtPosition( m_MissionPositions.Get( m_selectedMission ) , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_Farm_CowshedA")
			{	
				Object Farm = FoundObject;			 
				//Spawn some infected at farm
				for ( int j = 0 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	string RandomInfected = InfectedTypes.GetRandomElement();
					vector InfectedPos = Farm.ModelToWorld( PriInfectSpawns.Get(j) );
					DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}
				
				break;
			}	
		}								
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		//do nothing		
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "HuntingBag" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] ) ) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}
		
		//Check if container has desired amount of steaks collected at primary mission position
		if ( MissionObject && MissionObject.ClassName() == "HuntingBag" && !m_MissionExtended )
		{
			int CargoCount = MissionObject.GetInventory().CountInventory();
			int LastCount = 0;
			int FoundObjects;
			
			if ( CargoCount != LastCount )
			{
				FoundObjects = 0;
				
				if ( CargoCount >= ReqMeatAmount )
				{	
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
					
					for ( int i = 0; i < CargoCount; i++ )
					{
						EntityAI CargoItem = CargoItems1.GetItem(i);
						if ( CargoItem && CargoItem.GetType() == "PigSteakMeat" ) FoundObjects++;
						else continue;
												
						//When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
						if ( FoundObjects >= ReqMeatAmount )
						{
							Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ ReqMeatAmount +" MissionObjects in the container.");
							//delete container first
							GetGame().ObjectDelete( MissionObject );
							//call rewards spawn one second later 
							GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnRewards, 1000 );
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
				if ( FoundObject.GetType() == "Land_Misc_TrailRoof_Small" )
				{			 
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is "+ m_MissionDescription[3] +" Hiking Rest @ "+ m_MissionPosition );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
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
