#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public AppNative {
	CameraPersp camera;
	Vec3f eyePosition; 
	float cameraDistance;

	Vec3f objectPosition;
		Vec3f vectorPosX; 
		Vec3f vectorPosY;

public:
	void setup() 
	{ 
		vectorPosX.x = 1;
		vectorPosY.y = 1;
		objectPosition = Vec3f::zero();
		cameraDistance = 500; 
		camera.setPerspective(60.0f, getWindowAspectRatio(), 5.0f, 3000.0f); 
		
	}

	void keyDown(KeyEvent event) 
	{
		if (event.getCode() == KeyEvent::KEY_UP) {
			objectPosition.y += 10;
		}
		if (event.getCode() == KeyEvent::KEY_DOWN) {
			objectPosition.y -= 10;
		}
		if (event.getCode() == KeyEvent::KEY_LEFT) {
			objectPosition.x -= 10;
		}
		if (event.getCode() == KeyEvent::KEY_RIGHT) {
			objectPosition.x += 10;
		}
	}

	void update() 
	{ 
		eyePosition = Vec3f(0.0f, 0.0f, cameraDistance); 
		camera.lookAt(eyePosition, Vec3f::zero(), Vec3f::yAxis());
		gl::setMatrices(camera);
	}

	void draw() 
	{ 
		gl::clear(Color(0, 0.5f, 0.5f)); 
		gl::drawSphere(objectPosition, 25);
		gl::drawSphere(objectPosition - 3*vectorPosY, 25); //голова

		gl::drawCube(objectPosition - 40*vectorPosY, Vec3f(150.0f, 15.0f, 1.0f));  //крылья
		gl::drawCube(objectPosition - 55*vectorPosY, Vec3f(130.0f, 15.0f, 1.0f));
		gl::drawCube(objectPosition - 70*vectorPosY, Vec3f(110.0f, 15.0f, 1.0f));

		gl::drawCube(objectPosition - 100*vectorPosY, Vec3f(10.0f, 45.0f, 1.0f)); //хвост
		glColor3f(1.0f, 1.0f, 0.0f);
	}
};

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)