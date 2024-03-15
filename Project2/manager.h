#pragma once
#include <stdio.h>
#include "OrthogonalList.h"
#include "sch_struct.h"


typedef struct MANAGERACOUNT
{
	char username[20];
	char password[20];
	int issuperpowerd;//是否有超级管理权限
	struct MANAGERACOUNT*next;
}MANAGERACOUNT;

extern MANAGERACOUNT *manager_h;

void initmanager();


int managerlogin();