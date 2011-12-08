# Carnival LiveCam, Augmented reality made easy.
# Copyright (C) 2011  Gonzalo Exequiel Pedone
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with This program.  If not, see <http://www.gnu.org/licenses/>.
#
# Email   : hipersayan DOT x AT gmail DOT com
# Web-Site: http://hipersayanx.blogspot.com/

CONFIG += qt

DESTDIR += $$PWD

HEADERS += \
    include/plugin/plugin.h \
    include/plugin/plugininfo.h \
    include/plugin/pluginmanager.h \
    include/streaming/mediastreaming.h \
    include/streaming/outputformat.h \
    include/driver/driver.h \
    include/driver/driverfactory.h \
    include/driver/driverinfo.h \
    include/driver/deviceinfo.h \
    include/driver/drivermanager.h \
    include/driver/devicemanager.h \
    include/shell/shell.h \
    include/shell/shellfactory.h \
    include/shell/shellmanager.h \
    include/shell/shellinfo.h \
    include/core/core.h

target.path += /usr/bin

plugins.files = share/*
plugins.path = /usr/share/$$TARGET

INSTALLS += target \
            plugins

MOC_DIR += $$PWD/build

OBJECTS_DIR += $$PWD/build

QT += core gui

RCC_DIR += $$PWD/build

SOURCES += src/main.cpp \
    src/plugin/plugininfo.cpp \
    src/plugin/pluginmanager.cpp \
    src/streaming/mediastreaming.cpp \
    src/streaming/outputformat.cpp \
    src/driver/driverinfo.cpp \
    src/driver/deviceinfo.cpp \
    src/driver/drivermanager.cpp \
    src/driver/devicemanager.cpp \
    src/shell/shellmanager.cpp \
    src/shell/shellinfo.cpp \
    src/core/core.cpp

TEMPLATE += app

UI_DIR += $$PWD/build