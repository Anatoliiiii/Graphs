#pragma once
#include <iostream>
#include <string>
#include <vector>
template <typename T, typename U>
class Iterator
{
public:

	typedef typename std::vector<T>::iterator GraphIterator;


	Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data)
	{
		m_it_ = m_p_data_->vertexList.begin();
	}

	GraphIterator First()
	{
		return  m_p_data_->vertexList.begin();
	}

	void setCurrentToBegin()
	{
		m_it_ = m_p_data_->vertexList.begin();
	}

	void setCurrentToEnd() 
	{
		m_it_ = m_p_data_->vertexList.end();
	}

	void Next()
	{
		m_it_++;
	}

	void Prev() 
	{
		m_it_--;
	}

	GraphIterator  Last()
	{
		return	 m_p_data_->vertexList.end() - 1;
	}

	bool FromBegineToEnd() 
	{
		return (m_it_ == m_p_data_->vertexList.end());
	}

	bool FromEndToBegine() 
	{
		return (m_it_ + 1 == m_p_data_->vertexList.begin());
	}

	GraphIterator Current()
	{
		return m_it_;
	}



public:
	U* m_p_data_;

	GraphIterator m_it_;
};