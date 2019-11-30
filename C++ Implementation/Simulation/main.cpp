#include "mainwindow.h"

#include <QGuiApplication>

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <QEvent>
#include <Qt3DInput/QAbstractAxisInput>
#include <Qt3DCore>


#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>


#include <QPropertyAnimation>

#include "qt3dwindow.h"
#include "orbittransformcontroller.h"
#include "qorbitcameracontroller.h"

Qt3DCore::QEntity *createScene() {

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

        //Initialize Sphere Entity
        Qt3DCore::QEntity *cylinderEntity = new Qt3DCore::QEntity(rootEntity);
            Qt3DExtras::QCylinderMesh *cylinderMesh = new Qt3DExtras::QCylinderMesh;
            cylinderMesh->setRadius(3);
            cylinderMesh->setLength(10);


            Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform;
            OrbitTransformController *controller = new OrbitTransformController(cylinderTransform);
            controller->setTarget(cylinderTransform);
            controller->setRadius(10.0f);

            cylinderEntity->addComponent(cylinderMesh);
            cylinderEntity->addComponent(cylinderTransform);
            cylinderEntity->addComponent(material);

        // Initialize Directional Ray
         Qt3DCore::QRay3D *centerRay = new Qt3DCore::QRay3D(rootEntity);


            return rootEntity;

}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
       Qt3DExtras::Qt3DWindow view;

       Qt3DCore::QEntity *scene = createScene();

       // Camera
       Qt3DRender::QCamera *camera = view.camera();
       camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
       camera->setPosition(QVector3D(0, 0, 40.0f));
       camera->setViewCenter(QVector3D(0, 0, 0));

       // For camera controls
       Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
       camController->setLinearSpeed( 50.0f );
       camController->setLookSpeed( 180.0f );
       camController->setCamera(camera);

       view.setRootEntity(scene);
       view.show();

       return app.exec();
}
