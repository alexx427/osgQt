#ifndef QTOSGWIDGET_H
#define QTOSGWIDGET_H

#include <QOpenGLWidget>

#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>

class QtOSGWidget : public QOpenGLWidget
{
	Q_OBJECT

	public:
		explicit
		QtOSGWidget(QWidget* parent = nullptr)
			: QtOSGWidget(new osgViewer::Viewer, new osg::Camera, parent) {}

		explicit
		QtOSGWidget(
				osg::ref_ptr<osgViewer::Viewer> & viewer,
				osg::ref_ptr<osg::Camera> & camera,
				QWidget* parent = nullptr)
			: QtOSGWidget(viewer.get(), camera.get(), parent) {}

		QtOSGWidget(
				osgViewer::Viewer * viewer,
				osg::Camera * camera,
				QWidget* parent = nullptr);

		osg::ref_ptr<osgViewer::Viewer> & getViewer() { return viewer; }
		osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> & getGraphicsWindow() { return graphicsWindow; }

	protected:
		virtual void resizeGL(int w, int h) override;
		virtual void paintGL() override;

		osg::ref_ptr<osgViewer::Viewer> viewer = nullptr;
		osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindow = nullptr;
};

#endif // QTOSGWIDGET_H