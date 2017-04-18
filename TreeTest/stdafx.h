// stdafx.h: включаемый файл для стандартных системных включаемых файлов,
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"
#include <iostream>
// Заголовки CppUnitTest
#include "CppUnitTest.h"
// Redirect cout
static std::ostringstream out;
static std::streambuf* orig_buf(std::cout.rdbuf(out.rdbuf()));
// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
