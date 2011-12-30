#ifndef SPACE_H
#define SPACE_H

#include <QObject>
#include <QPointF>
#include <QSizeF>
#include <QRectF>

class Space: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString spaceId READ spaceId WRITE setSpaceId RESET resetSpaceId)
    Q_PROPERTY(int nParts READ nParts WRITE setNParts RESET resetNParts)
    Q_PROPERTY(qreal scale READ scale WRITE setScale RESET resetScale)
    Q_PROPERTY(QPointF center READ center WRITE setCenter RESET resetCenter)
    Q_PROPERTY(QSizeF size READ size WRITE setSize RESET resetSize)
    Q_PROPERTY(bool snapping READ snapping WRITE setSnapping RESET resetSnapping)
    Q_PROPERTY(qreal snappingPT READ snappingPT WRITE setSnappingPT RESET resetSnappingPT)
    Q_PROPERTY(qreal snappingRT READ snappingRT WRITE setSnappingRT RESET resetSnappingRT)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation RESET resetRotation)
    Q_PROPERTY(bool maximized READ maximized WRITE setMaximized RESET resetMaximized)

    public:
        explicit Space(QObject *parent = 0);
        Space(const Space &object);
        Space(QString spaceId, QPointF center, QSizeF size, qreal scale, qreal rotation);
        Space& operator =(const Space &other);
        bool operator ==(const Space &other) const;
        Q_INVOKABLE bool isMaximized();
        Q_INVOKABLE void toggleMaximized(const QList<qreal> &hLines = QList<qreal>(), const QList<qreal> &vLines = QList<qreal>());
        Q_INVOKABLE void setRef();
        Q_INVOKABLE void resetStatus();
        Q_INVOKABLE QList<qreal> hLines();
        Q_INVOKABLE QList<qreal> vLines();
        Q_INVOKABLE void move(QPointF pos, const QList<qreal> &hLines = QList<qreal>(), const QList<qreal> &vLines = QList<qreal>());
        Q_INVOKABLE void scaleAndRotate(qreal factor, qreal rotation, const QList<qreal> &hLines, const QList<qreal> &vLines);
        Q_INVOKABLE bool contains(QPointF point = QPointF(0, 0));
        Q_INVOKABLE QRectF boundRect();

        QString spaceId();
        int nParts();
        qreal scale();
        QPointF center();
        QSizeF size();
        bool snapping();
        qreal snappingPT();
        qreal snappingRT();
        qreal rotation();
        bool maximized();

    private:
        QList<qreal> m_snapAngles;
        QString m_spaceId;
        int m_nParts;
        QPointF m_center;
        QPointF m_CenterRef;
        QSizeF m_size;
        QSizeF m_sizeRef;
        bool m_snapping;
        qreal m_snappingPT;
        qreal m_snappingRT;
        qreal m_scale;
        qreal m_scaleRef;
        qreal m_rotation;
        qreal m_rotationRef;
        bool m_maximized;

        template <typename T> T min(const QList<T> &list);
        template <typename T> T max(const QList<T> &list);
        QSizeF internalRectSize(QSizeF size = QSizeF(0, 0));

    public slots:
        void setSpaceId(QString value);
        void setNParts(int value);
        void setCenter(QPointF value);
        void setSize(QSizeF value);
        void setSnapping(bool value);
        void setSnapping(bool snapping, int nParts, qreal snappingPT, qreal snappingRT);
        void setSnappingPT(qreal value);
        void setSnappingRT(qreal value);
        void setScale(qreal value);
        void setScale(qreal factor, const QList<qreal> &hLines, const QList<qreal> &vLines);
        void setRotation(qreal rotation);
        void setMaximized(bool value);
        void resetSpaceId();
        void resetNParts();
        void resetCenter();
        void resetSize();
        void resetSnapping();
        void resetSnappingPT();
        void resetSnappingRT();
        void resetScale();
        void resetRotation();
        void resetMaximized();
};

#endif // SPACE_H