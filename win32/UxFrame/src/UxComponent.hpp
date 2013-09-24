#pragma once

#include <Windows.h>
#include <GdiPlus.h>
#include <memory>

namespace Ux {

class Component
{
public:
	Component();
	virtual ~Component();

	bool visible() const;
	void visible(bool v);

	int x() const;
	int y() const;
	void x(int x);
	void y(int y);

	virtual void createMe(HWND hParent) = 0;
	virtual void onDraw(Gdiplus::Graphics& g) = 0;
	virtual void onDestroy() = 0;

	HWND getHWND() const { return hWnd_; }

protected:
	HWND hWnd_;
	bool visible_;
	int x_, y_;
};
typedef std::shared_ptr<Component> ComponentPtr;

}
