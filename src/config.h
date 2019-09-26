/*
** config.h
**
** This file is part of mkxp.
**
** Copyright (C) 2013 Jonas Kulla <Nyocurio@gmail.com>
**
** mkxp is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** mkxp is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with mkxp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <set>

struct Config
{
	int rgssVersion = 0;

	bool debugMode = false;
	bool printFPS = false;

	bool winResizable = false;
	bool fullscreen = false;
	bool fixedAspectRatio = true;
	bool smoothScaling = true;
	bool vsync = false;

	std::string windowTitle;
	int defScreenW = 0;
	int defScreenH = 0;

	int fixedFramerate = 0;
	bool frameSkip =true;
	bool syncToRefreshrate = false;

	bool solidFonts = false;

	bool subImageFix = false;
	bool enableBlitting = true;
	int maxTextureSize = 0;

	std::string gameFolder = ".";
	bool anyAltToggleFS = false;
	bool enableReset = true;
	bool allowSymlinks = false;
	bool pathCache=true;

	std::string dataPathOrg;
	std::string dataPathApp;

	std::string iconPath;
	std::string execName = "Game";
	std::string titleLanguage;

	struct
	{
		std::string soundFont;
		bool chorus = false;
		bool reverb = false;
	} midi;

	struct
	{
		int sourceCount = 6;
	} SE;

	bool useScriptNames = false;

	std::string customScript;
	std::set<std::string> preloadScripts;
	std::vector<std::string> rtps;

	std::vector<std::string> fontSubs;

	std::vector<std::string> rubyLoadpaths;

	/* Editor flags */
	struct {
		bool debug;
		bool battleTest;
	} editor;

	/* Game INI contents */
	struct {
		std::string scripts;
		std::string title;
	} game;

	/* Internal */
	std::string customDataPath;
	std::string commonDataPath;

	Config();

	void read(int argc, char *argv[]);
	void readGameINI();
};

#endif // CONFIG_H
