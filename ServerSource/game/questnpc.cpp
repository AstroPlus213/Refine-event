// Before :

	bool NPC::OnItemInformer(PC& pc, unsigned int vnum)

// Add :

#ifdef ENABLE_REFINE_EVENT
	bool NPC::OnRefineItem(PC& pc, LPITEM item)
	{
		if (item)
			return HandleEvent(pc, QUEST_REFINE_EVENT);
		else
			return HandleReceiveAllEvent(pc, QUEST_REFINE_EVENT);
	}
#endif
