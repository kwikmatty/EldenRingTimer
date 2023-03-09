#include "BossNames.h"
#include <iostream>

#define INITIALIZED 0

//#if INITIALIZED == 1

MainBossList* MainBossList::createNode(MainBossList* current, MainBossList* Next, MainBossList* Previous, std::string mainboss_name)
{
	while (current != nullptr)
	{
		current->next = Next;

		current->mainboss_Name = mainboss_name;

		if (Next == nullptr)
		{
			current->next = nullptr;
		}

		if (previous == nullptr)
		{
			current->previous = nullptr;
		}

		break;
	}
	return current;
}

MainBossList* MainBossList::printList(MainBossList* head)
{
	while (head != nullptr)
	{
		std::cout << "Boss Name: " << head->mainboss_Name << "\n";

		head = head->next;
	}

	return head;
}

//#endif

void Init()
{
#undef INITALIZED
#define INITALIZED 1

	std::cout << "Main Boss List Initialized!\n";
}