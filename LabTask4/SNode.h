#pragma once
//шаблон узла
template< class T >
struct SNode
{
	T value;
	SNode* pNext;
};