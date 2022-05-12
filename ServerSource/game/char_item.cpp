// Do this step twice!!
// Search :

			LogManager::instance().ItemLog(this, pkNewItem, "REFINE SUCCESS", pkNewItem->GetName());

// Add :

#ifdef ENABLE_REFINE_EVENT
			quest::CQuestManager::instance().RefineItem(GetPlayerID(), pkNewItem);
#endif
