// SHE library
// Copyright (C) 2021 LibreSprite contributors
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#pragma once

#include "she/display.h"

#if (defined(_WIN32) || defined(__linux__)) && !defined(ANDROID)
#if defined(USE_EASYTAB)
#include <EasyTab/easytab.h>
#undef None
#endif
#endif

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Cursor;
struct SDL_Rect;

namespace she
{

class SDL2Display : public Display {
	friend class SDL2System;

    public:
	SDL2Display(int width, int height, int scale);
	~SDL2Display();

	void dispose() override;
	void toggleFullscreen() override;
	bool setIcon(Surface *) override;
	int width() const override;
	int height() const override;
	void setWidth(int);
	void setHeight(int);
	int originalWidth() const override;
	int originalHeight() const override;
	void setOriginalWidth(int width);
	void setOriginalHeight(int height);
	int scale() const override;
	void setScale(int scale) override;
	void recreateSurface();
	Surface *getSurface() override;
	void flip(const gfx::Rect &bounds) override;
	void maximize() override;
	bool isMaximized() const override;
	bool isMinimized() const override;
	void setTitleBar(const std::string &title) override;
	NativeCursor nativeMouseCursor() override;
	bool setNativeMouseCursor(NativeCursor cursor) override;
	void setMousePosition(const gfx::Point &position) override;
	void captureMouse() override;
	void releaseMouse() override;
	std::string getLayout() override;
	void setLayout(const std::string &layout) override;
	void *nativeHandle() override;

	void present() override;
	SDL_Renderer *renderer()
	{
		return m_renderer;
	}

	static inline bool gpu{};

    private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	Surface *m_surface{};
	Surface *m_doublebuffer{};
	int m_scale;
	int m_width;
	int m_height;
	NativeCursor m_nativeCursor;
	int m_restoredWidth;
	int m_restoredHeight;
	bool m_isFullscreen = false;
	bool m_dirty = true;
};

extern SDL2Display *unique_display;

} // namespace she
