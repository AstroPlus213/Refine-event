// Before :

			bool	OnSIGUse(PC& pc, bool bReceiveAll);

// Add :

#ifdef ENABLE_REFINE_EVENT
			bool	OnRefineItem(PC& pc, LPITEM item);
#endif
