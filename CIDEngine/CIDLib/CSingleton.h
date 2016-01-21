#pragma once

template <class T>

class CSingleton
{
private:
	static T* _single;

public:
	CSingleton()
	{
	};

	virtual ~CSingleton()
	{ 
		delete _single; 	
	}

	static T* getInstance()
	{ 
		if (_single == NULL)
		{
			_single = new T(); 
		}

		return _single; 
	}
};

template <class T> T* CSingleton<T>::_single = 0;