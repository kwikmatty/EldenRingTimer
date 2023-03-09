#pragma once
//pre-processor command, only include this file once, is a header guard and prevents multiple translation units to have the same function names (can cause function collisions)

#include <iostream>

class MainBossList
{
public:
	MainBossList* next;
	MainBossList* previous;

	double timing[18];

	std::string mainboss_Name;

public:

	MainBossList* createNode(MainBossList* current, MainBossList* Next, MainBossList* Previous, std::string mainboss_name);

	MainBossList* printList(MainBossList* head);
};

void Init();
