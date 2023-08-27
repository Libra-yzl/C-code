#pragma once

namespace yzl
{
	template <class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		Iterator _cur;

		typedef ReverseIterator<Iterator, Ref, Ptr> self;

		ReverseIterator(Iterator it)
			:_cur(it)
		{}

		bool operator!=(const self& it)
		{
			return _cur != it._cur;
		}

		Ref operator*()
		{
			Iterator tmp = _cur;
			return *--tmp;
		}

		self& operator++()
		{
			--_cur;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			--_cur;

			return tmp;
		}


		self& operator--()
		{
			++_cur;
			return *this;
		}

		Ptr operator->()
		{
			return &_cur;
		}
	};
}