#pragma once

template <class T>

class Singleton
{
	//이거 전부 어떻게 작동하는지 일일이 줄마다 적어줘 이게 제일이 해가 안가 이거때문에 디자인패턴 책도 샀는데 막 와닿지가 않아서 그래 ㅎㅎㅈㅅㅈㅅ
private:
	static T* _insntance;
public:
	static T* GetInstance()
	{
		if (_insntance == nullptr)
			_insntance = new T();
		return _insntance;
	}
};

template <class T> T* Singleton<T>::_insntance = nullptr;

class Time
{
public:
	static float deltaTime;
	static float timeScale;
};
