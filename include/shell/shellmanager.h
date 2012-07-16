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

#ifndef SHELLMANAGER_H
#define SHELLMANAGER_H

#include <QVariant>
#include <QPluginLoader>
#include <QPushButton>

#include "shell.h"
#include "shellinfo.h"

class ShellManager: public QObject
{
    Q_OBJECT

    public:
        explicit ShellManager(QObject *parent = 0);
        ~ShellManager();
        Q_INVOKABLE QList<QVariant> shellsInfoList();
        Q_INVOKABLE QWidget *widget(QString shellId = "");
        Q_INVOKABLE QSize viewPortSize(QString shellId = "");
        Q_INVOKABLE QString showPreview(QString shellId = "");

    private:
        QPluginLoader shellLoader;
        QString activeShellId;
        Shell *activeShell;
        QHash<QString, ShellInfo> shellsInfo;
        QHash<QString, QVariant> shellConfigs;

    public slots:
        bool setShell(QString shellId);
        bool enableShell(QString shellId);
        bool disableShell(QString shellId);
        void configureShell(QString shellId);
        void setFrame(const QImage &frame);
        void setPreview(const QImage &frame);
        void updateDevices(const QList<QVariant> &devices, const QStringList &activeSpaces);
        void updatePlugins(const QList<QVariant> &plugins);
        void setControlButtons(QPushButton *toggleMaximizedButton = NULL, QPushButton *scaleAndRotateButton = NULL);
        void moveDevice(qint32 from, qint32 to);

    private slots:
        void onToggleEditMode();
        void onViewPortSizeChanged(QSize size);
        void onMouseDoubleClicked(QMouseEvent *event);
        void onMousePositionChanged(QMouseEvent *event);
        void onMousePressed(QMouseEvent *event);
        void onMouseReleased(QMouseEvent *event);
        void onTakePicture();
        void onStartStopRecord();
        void onEnabledDeviceMoved(qint32 from, qint32 to);
        void onDeviceEnable(QString deviceId);
        void onDeviceDisable(QString deviceId);
        void onSetEffect(QString pluginId, QString spaceId);
        void onUnsetEffect(QString pluginId, QString spaceId);
        void onPluginMoved(QString spaceId, qint32 from, qint32 to);
        void onPluginConfigureClicked(QString pluginId);
        void onDeviceConfigureClicked(QString deviceId);
        void onClosed();

    signals:
        void toggleEditMode();
        void viewPortSizeChanged(QSize size);
        void mouseDoubleClicked(QMouseEvent *event);
        void mousePositionChanged(QMouseEvent *event);
        void mousePressed(QMouseEvent *event);
        void mouseReleased(QMouseEvent *event);
        void enabledDeviceMoved(qint32 from, qint32 to);

        /*!
          \fn void ShellManager::takePicture()

          \brief This signal is emited when the user presses the "take picture" button.
         */
        void takePicture();

        /*!
          \fn void ShellManager::startStopRecord()

          \brief This signal is emited when the user presses the "start/stop video record" button.
         */
        void startStopRecord();

        void deviceEnable(QString deviceId);
        void deviceDisable(QString deviceId);

        /*!
          \fn void ShellManager::pluginActivated(QString pluginId)

          \param pluginId Unique plugin identifier.

          \brief This signal is emited when the user activate a plugin.
         */
        void setEffect(QString pluginId, QString spaceId);

        /*!
          \fn void ShellManager::pluginDeactivated(QString pluginId)

          \param pluginId Unique plugin identifier.

          \brief This signal is emited when the user deactivate a plugin.
         */
        void unsetEffect(QString pluginId, QString spaceId);

        /*!
          \fn void ShellManager::pluginMoved(qint32 from, qint32 to)

          \param from The old index position of the plugin.
          \param to The new index position of the plugin.

          \brief This signal is emited when the user changes the index of a plugin.
         */
        void pluginMoved(QString spaceId, qint32 from, qint32 to);

        /*!
          \fn void ShellManager::pluginConfigureClicked(QString pluginId)

          \param pluginId The plugin to configure.

          \brief This signal is emited when the user wants to configure a plugin.
         */
        void pluginConfigureClicked(QString pluginId);

        /*!
          \fn void ShellManager::deviceConfigureClicked(QString deviceId)

          \param deviceId The device to configure.

          \brief This signal is emited when the user wants to configure a device.
         */
        void deviceConfigureClicked(QString deviceId);

        /*!
          \fn void ShellManager::closed()

          \brief This signal is emited when the shell is closed.
         */
        void closed();
};

#endif // SHELLMANAGER_H
