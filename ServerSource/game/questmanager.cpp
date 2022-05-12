// Search :

		m_mapEventName.insert(TEventNameMap::value_type("item_informer", QUEST_ITEM_INFORMER_EVENT));	// 독일선물기능테스트

// Add :

#ifdef ENABLE_REFINE_EVENT
		m_mapEventName.insert(TEventNameMap::value_type("refine", QUEST_REFINE_EVENT));
#endif


// Search :

	bool CQuestManager::SIGUse(unsigned int pc, DWORD sig_vnum, LPITEM item, bool bReceiveAll)

// Before it add :

#ifdef ENABLE_REFINE_EVENT
	bool CQuestManager::RefineItem(unsigned int pc, LPITEM item)
	{
		if (test_server)
			sys_log(0, "questmanager::RefineItem Start : itemVnum : %d PC : %d", item->GetOriginalVnum(), pc);

		PC* pPC;
		if ((pPC = GetPC(pc)))
		{
			if (!CheckQuestLoaded(pPC))
			{
				LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pc);

				if (ch)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, "Your request is loading. Please be patient.");
				}
				return false;
			}

			if (!item)
				return false;

			SetCurrentItem(item);

			m_mapNPC[QUEST_NO_NPC].OnRefineItem(*pPC, item);
			return m_mapNPC[item->GetVnum()].OnRefineItem(*pPC, item);
		}
		else
		{
			sys_err("QUEST REFINE_ITEM_EVENT no such pc id : %d", pc);
			return false;
		}
	}
#endif
