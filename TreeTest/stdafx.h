// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������,
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"
#include <iostream>
// ��������� CppUnitTest
#include "CppUnitTest.h"
// Redirect cout
static std::ostringstream out;
static std::streambuf* orig_buf(std::cout.rdbuf(out.rdbuf()));
// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
