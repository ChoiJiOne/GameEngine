#pragma once

#include "Vector.hpp"


/**
 * @brief ���� ������ �����մϴ�.
 */
using LinearColor = Vec4f;


/**
 * @brief �⺻ ������ �����մϴ�.
 */
const LinearColor BLACK   = LinearColor(0.0f, 0.0f, 0.0f, 1.0f);
const LinearColor RED     = LinearColor(1.0f, 0.0f, 0.0f, 1.0f);
const LinearColor GREEN   = LinearColor(0.0f, 1.0f, 0.0f, 1.0f);
const LinearColor BLUE    = LinearColor(0.0f, 0.0f, 1.0f, 1.0f);
const LinearColor YELLOW  = LinearColor(1.0f, 1.0f, 0.0f, 1.0f);
const LinearColor MAGENTA = LinearColor(1.0f, 0.0f, 1.0f, 1.0f);
const LinearColor CYAN    = LinearColor(0.0f, 1.0f, 1.0f, 1.0f);
const LinearColor WHITE   = LinearColor(1.0f, 1.0f, 1.0f, 1.0f);
const LinearColor GRAY    = LinearColor(0.5f, 0.5f, 0.5f, 1.0f);