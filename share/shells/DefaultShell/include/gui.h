// Carnival LiveCam, Augmented reality made easy.
// Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
//
// Carnival LiveCam is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Carnival LiveCam is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Carnival LiveCam.  If not, see <http://www.gnu.org/licenses/>.
//
// Email   : hipersayan DOT x AT gmail DOT com
// Web-Site: https://github.com/hipersayanX/Carnival-LiveCam

#ifndef GUI_H
#define GUI_H

#include <QDeclarativeView>
#include <QDeclarativeItem>
#include <QMouseEvent>

#include "webcamimageprovider.h"

class Gui: public QDeclarativeView
{
    Q_OBJECT

    public:
        explicit Gui(QWidget *parent=0);
        QString showPreview();

    private:
        WebcamImageProvider *webcamImageProvider;
        QObject *root;
        QDeclarativeItem *devices;
        QDeclarativeItem *iconBar;
        QDeclarativeItem *effects;
        QDeclarativeItem *windowControls;
        QDeclarativeItem *windowBackground;
        QPoint windowPos0;
        QPoint mousePos0;
        QSize windowSize0;
        uchar currentFrame;

    signals:
        void viewPortSizeChanged(QSize size);
        void sMouseDoubleClicked(QMouseEvent *event);
        void sMousePositionChanged(QMouseEvent *event);
        void sMousePressed(QMouseEvent *event);
        void sMouseReleased(QMouseEvent *event);
        void toggleEditMode();
        void takePicture();
        void startStopRecord();
        void enabledDeviceMoved(qint32 from, qint32 to);
        void deviceEnable(QString deviceId);
        void deviceDisable(QString deviceId);
        void setEffect(QString pluginId, QString spaceId);
        void unsetEffect(QString pluginId, QString spaceId);
        void pluginMoved(QString spaceId, qint32 from, qint32 to);
        void pluginConfigureClicked(QString pluginId);
        void deviceConfigureClicked(QString deviceId);
        void closed();

    public slots:
        void setFrame(const QImage &frame);
        void setPreview(const QImage &frame);
        void moveDevice(qint32 from, qint32 to);
        void updateDevices(const QList<QVariant> &devices, const QStringList &activeSpaces);
        void updatePlugins(const QList<QVariant> &plugins);

    private slots:
        void onViewPortSizeChanged(int width, int height);
        void iconClicked(int index=0);
        void onEnabledDeviceMoved(int from, int to);
        void onDeviceEnable(QString deviceId);
        void onDeviceDisable(QString deviceId);
        void onSetEffect(QString pluginId, QString spaceId);
        void onUnsetEffect(QString pluginId, QString spaceId);
        void onPluginMoved(QString spaceId, int from, int to);
        void onPluginConfigureClicked(QString pluginId);
        void onDeviceConfigureClicked(QString deviceId);
        void onMouseDoubleClicked(qreal mouseX, qreal mouseY, QVariant pressedButtons);
        void onMousePositionChanged(qreal mouseX, qreal mouseY, QVariant pressedButtons);
        void onMousePressed(qreal mouseX, qreal mouseY, QVariant pressedButtons);
        void onMouseReleased(qreal mouseX, qreal mouseY, QVariant pressedButtons);
        void onEnteredMove();
        void onBeginMove();
        void onMove();
        void onExitedMove();
        void onMinimize();
        void onStayOnTop();
        void onMaximize();
        void onClose();
        void onEnteredResizeTopLeft();
        void onBeginResizeTopLeft();
        void onResizeTopLeft();
        void onExitedResizeTopLeft();
        void onEnteredResizeBottomLeft();
        void onBeginResizeBottomLeft();
        void onResizeBottomLeft();
        void onExitedResizeBottomLeft();
        void onEnteredResizeBottomRight();
        void onBeginResizeBottomRight();
        void onResizeBottomRight();
        void onExitedResizeBottomRight();
        void onEnteredResizeLeft();
        void onBeginResizeLeft();
        void onResizeLeft();
        void onExitedResizeLeft();
        void onEnteredResizeRight();
        void onBeginResizeRight();
        void onResizeRight();
        void onExitedResizeRight();
        void onEnteredResizeTop();
        void onBeginResizeTop();
        void onResizeTop();
        void onExitedResizeTop();
        void onEnteredResizeBottom();
        void onBeginResizeBottom();
        void onResizeBottom();
        void onExitedResizeBottom();
};

#endif // GUI_H
