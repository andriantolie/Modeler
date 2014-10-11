// The Gundam model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a GundamModel, we inherit off of ModelerView
class GundamModel : public ModelerView
{
public:
	GundamModel(int x, int y, int w, int h, char *label);

	virtual void draw();

private:
	double upperBodySize[3];
	double lowerBodySize[3];
	double headSize[3];

	double rightShoulderSize[3];
	double rightUpperArmSize[3];
	double rightLowerArmSize[3];
	double rightFistSize[3];
	double leftShoulderSize[3];
	double leftUpperArmSize[3];
	double leftLowerArmSize[3];
	double leftFistSize[3];

	double rightThighSize[3];
	double rightUpperLegSize[3];
	double rightLowerLegSize[3];
	double rightFootSize[3];
	double leftThighSize[3];
	double leftUpperLegSize[3];
	double leftLowerLegSize[3];
	double leftFootSize[3];

	void drawUpperBody();
	void drawLowerBody();
	void drawHead();

	void drawRightShoulder();
	void drawRightUpperArm();
	void drawRightLowerArm();
	void drawRightFist();

	void drawLeftShoulder();
	void drawLeftUpperArm();
	void drawLeftLowerArm();
	void drawLeftFist();

	void drawRightThigh();
	void drawRightUpperLeg();
	void drawRightLowerLeg();
	void drawRightFoot();

	void drawLeftThigh();
	void drawLeftUpperLeg();
	void drawLeftLowerLeg();
	void drawLeftFoot();
		
};

//[0] is x-axis, [1] is y-axis, [2] is z-axis
GundamModel::GundamModel(int x, int y, int w, int h, char *label)
: ModelerView(x, y, w, h, label) {
	upperBodySize[0] = 4;
	upperBodySize[1] = 4;
	upperBodySize[2] = 2;

	lowerBodySize[0] = 1.5;
	lowerBodySize[1] = 2.5;
	lowerBodySize[2] = 2;

	headSize[0] = 2;
	headSize[1] = 2;
	headSize[2] = 2;

	rightShoulderSize[0] = 1.5;
	rightShoulderSize[1] = 2;
	rightShoulderSize[2] = 2;

	rightUpperArmSize[0] = 1;
	rightUpperArmSize[1] = 1;
	rightUpperArmSize[2] = 2;

	rightLowerArmSize[0] = 1.5;
	rightLowerArmSize[1] = 2.5;
	rightLowerArmSize[2] = 2;

	rightFistSize[0] = 0.5;
	rightFistSize[1] = 0.5;
	rightFistSize[2] = 2;

	leftShoulderSize[0] = 1.5;
	leftShoulderSize[1] = 2;
	leftShoulderSize[2] = 2;

	leftUpperArmSize[0] = 1;
	leftUpperArmSize[1] = 1;
	leftUpperArmSize[2] = 2;

	leftLowerArmSize[0] = 1.5;
	leftLowerArmSize[1] = 2.5;
	leftLowerArmSize[2] = 2;

	leftFistSize[0] = 0.5;
	leftFistSize[1] = 0.5;
	leftFistSize[2] = 2;

	rightThighSize[0] = 1.5;
	rightThighSize[1] = 2;
	rightThighSize[2] = 2;

	rightUpperLegSize[0] = 1;
	rightUpperLegSize[1] = 1;
	rightUpperLegSize[2] = 2;

	rightLowerLegSize[0] = 1.5;
	rightLowerLegSize[1] = 2.5;
	rightLowerLegSize[2] = 2;

	rightFootSize[0] = 1.75;
	rightFootSize[1] = 0.5;
	rightFootSize[2] = 2;

	leftThighSize[0] = 1.5;
	leftThighSize[1] = 2;
	leftThighSize[2] = 2;

	leftUpperLegSize[0] = 1;
	leftUpperLegSize[1] = 1;
	leftUpperLegSize[2] = 2;

	leftLowerLegSize[0] = 1.5;
	leftLowerLegSize[1] = 2.5;
	leftLowerLegSize[2] = 2;

	leftFootSize[0] = 1.75;
	leftFootSize[1] = 0.5;
	leftFootSize[2] = 2;

}

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createGundamModel(int x, int y, int w, int h, char *label)
{
	return new GundamModel(x, y, w, h, label);
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out GundamModel
void GundamModel::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

	// draw the floor
	//setAmbientColor(.1f, .1f, .1f);
	//setDiffuseColor(COLOR_RED);
	//glPushMatrix();
	//glTranslated(-5, 0, -5);
	//drawBox(10, 0.01f, 10);
	//glPopMatrix();

	// draw the Gundam model
	// draw the torso
	setAmbientColor(1.0f, 1.0f, 1.0f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

		drawUpperBody();
        //draw head
		glPushMatrix();
		glTranslated(0, upperBodySize[1], 0);
		drawHead();
		glPopMatrix();

		//draw right arm
		glPushMatrix();
		//draw right shoulder
		glTranslated(upperBodySize[0]/2, upperBodySize[1]-rightShoulderSize[0]/2, 0);
		glRotated(-90, 0.0, 0.0, 1.0);
		drawRightShoulder(); 
			//draw right upper arm
			glTranslated(rightShoulderSize[0]/2, rightShoulderSize[1]/2, 0);
			glRotated(-90, 0.0, 0.0, 1.0);
			drawRightUpperArm();
			    //draw right lower arm
				glTranslated(0.0, rightUpperArmSize[1], 0.0);
				drawRightLowerArm();
					//draw right Foot
					glTranslated(0.0, rightLowerArmSize[1], 0.0);
					drawRightFist();
		glPopMatrix();

		//draw left arm
		glPushMatrix();
		//draw left shoulder
		glTranslated(-upperBodySize[0] / 2, upperBodySize[1] - leftShoulderSize[0] / 2, 0);
		glRotated(90, 0.0, 0.0, 1.0);
		drawRightShoulder();
		//draw left upper arm
		glTranslated(-leftShoulderSize[0] / 2, leftShoulderSize[1] / 2, 0);
		glRotated(90, 0.0, 0.0, 1.0);
		drawRightUpperArm();
		//draw left lower arm
		glTranslated(0.0, leftUpperArmSize[1], 0.0);
		drawRightLowerArm();
		//draw left Foot
		glTranslated(0.0, leftLowerArmSize[1], 0.0);
		drawRightFist();
		glPopMatrix();


		//draw lower body
		glPushMatrix();
		glRotated(180, 0.0, 0.0, 1.0);
		drawLowerBody();
		glPopMatrix();
			//draw right leg
			glPushMatrix();
			//draw right thigh
			glRotated(180, 0.0, 0.0, 1.0);
			glTranslated(-lowerBodySize[0]/2, lowerBodySize[1]/4, 0.0);
			glTranslated(-rightThighSize[0]/2, 0.0, 0.0);
			drawRightThigh();
				//draw right upper leg
				glTranslated(0.0, rightThighSize[1], 0.0);
				drawRightUpperLeg();
				    //draw right lower leg
					glTranslated(0.0, rightUpperLegSize[1], 0.0);
					drawRightLowerLeg();
					    //draw right foot
						glTranslated(0.0, rightLowerLegSize[1], 0.0);
						drawRightFoot();
			glPopMatrix();

			//draw left leg
			glPushMatrix();
			//draw left thigh
			glRotated(180, 0.0, 0.0, 1.0);
			glTranslated(lowerBodySize[0]/2, lowerBodySize[1] / 4, 0.0);
			glTranslated(leftThighSize[0]/2, 0.0, 0.0);
			drawRightThigh();
			//draw left upper leg
			glTranslated(0.0, leftThighSize[1], 0.0);
			drawRightUpperLeg();
			//draw left lower leg
			glTranslated(0.0, leftUpperLegSize[1], 0.0);
			drawRightLowerLeg();
			//draw left foot
			glTranslated(0.0, leftLowerLegSize[1], 0.0);
			drawRightFoot();
			glPopMatrix();
		glPopMatrix();
}

//OpenGl command to draw upper body
void GundamModel::drawUpperBody(){
	glPushMatrix();
	glTranslated(-upperBodySize[0]/2, 0, -upperBodySize[2]/2);
	glScaled(upperBodySize[0], upperBodySize[1], upperBodySize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLowerBody(){
	glPushMatrix();
	glTranslated(-lowerBodySize[0] / 2, 0, -lowerBodySize[2] / 2);
	glScaled(lowerBodySize[0], lowerBodySize[1], lowerBodySize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawHead(){
	glPushMatrix();
	    //draw neck
		glPushMatrix();
		glTranslated(-headSize[0] / 6, 0, -headSize[2] / 6);
		glScaled(headSize[0]/3, headSize[1]/6, headSize[2]/3);
		drawBox(1, 1, 1);
		glPopMatrix();
		//draw head
		glPushMatrix();
		glTranslated(-headSize[0] / 2, headSize[1]/6, -headSize[2] / 2);
		glScaled(headSize[0], headSize[1], headSize[2]);
		drawBox(1, 1, 1);
		glPopMatrix();
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightShoulder(){
	glPushMatrix();
	glTranslated(-rightShoulderSize[0] / 2, 0, -rightShoulderSize[2] / 2);
	glScaled(rightShoulderSize[0], rightShoulderSize[1], rightShoulderSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightUpperArm(){
	glPushMatrix();
	glTranslated(-rightUpperArmSize[0] / 2, 0, -rightUpperArmSize[2] / 2);
	glScaled(rightUpperArmSize[0], rightUpperArmSize[1], rightUpperArmSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightLowerArm(){
	glPushMatrix();
	glTranslated(-rightLowerArmSize[0] / 2, 0, -rightLowerArmSize[2] / 2);
	glScaled(rightLowerArmSize[0], rightLowerArmSize[1], rightLowerArmSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightFist(){
	glPushMatrix();
	glTranslated(-rightFistSize[0] / 2, 0, -rightFistSize[2] / 2);
	glScaled(rightFistSize[0], rightFistSize[1], rightFistSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftShoulder(){
	glPushMatrix();
	glTranslated(-leftShoulderSize[0] / 2, 0, -leftShoulderSize[2] / 2);
	glScaled(leftShoulderSize[0], leftShoulderSize[1], leftShoulderSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftUpperArm(){
	glPushMatrix();
	glTranslated(-leftUpperArmSize[0] / 2, 0, -leftUpperArmSize[2] / 2);
	glScaled(leftUpperArmSize[0], leftUpperArmSize[1], leftUpperArmSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftLowerArm(){
	glPushMatrix();
	glTranslated(-leftLowerArmSize[0] / 2, 0, -leftLowerArmSize[2] / 2);
	glScaled(leftLowerArmSize[0], leftLowerArmSize[1], leftLowerArmSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftFist(){
	glPushMatrix();
	glTranslated(-leftFistSize[0] / 2, 0, -leftFistSize[2] / 2);
	glScaled(leftFistSize[0], leftFistSize[1], leftFistSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightThigh(){
	glPushMatrix();
	glTranslated(-rightThighSize[0] / 2, 0, -rightThighSize[2] / 2);
	glScaled(rightThighSize[0], rightThighSize[1], rightThighSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightUpperLeg(){
	glPushMatrix();
	glTranslated(-rightUpperLegSize[0] / 2, 0, -rightUpperLegSize[2] / 2);
	glScaled(rightUpperLegSize[0], rightUpperLegSize[1], rightUpperLegSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightLowerLeg(){
	glPushMatrix();
	glTranslated(-rightLowerLegSize[0] / 2, 0, -rightLowerLegSize[2] / 2);
	glScaled(rightLowerLegSize[0], rightLowerLegSize[1], rightLowerLegSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawRightFoot(){
	glPushMatrix();
	glTranslated(-rightFootSize[0] / 2, 0, -rightFootSize[2] / 2);
	glScaled(rightFootSize[0], rightFootSize[1], rightFootSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}


//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftThigh(){
	glPushMatrix();
	glTranslated(-leftThighSize[0] / 2, 0, -leftThighSize[2] / 2);
	glScaled(leftThighSize[0], leftThighSize[1], leftThighSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftUpperLeg(){
	glPushMatrix();
	glTranslated(-leftUpperLegSize[0] / 2, 0, -leftUpperLegSize[2] / 2);
	glScaled(leftUpperLegSize[0], leftUpperLegSize[1], leftUpperLegSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftLowerLeg(){
	glPushMatrix();
	glTranslated(-leftLowerLegSize[0] / 2, 0, -leftLowerLegSize[2] / 2);
	glScaled(leftLowerLegSize[0], leftLowerLegSize[1], leftLowerLegSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

//OpenGl command to draw lower body
//TODO
void GundamModel::drawLeftFoot(){
	glPushMatrix();
	glTranslated(-leftFootSize[0] / 2, 0, -leftFootSize[2] / 2);
	glScaled(leftFootSize[0], leftFootSize[1], leftFootSize[2]);
	drawBox(1, 1, 1);
	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];
	controls[XPOS] = ModelerControl("X Position", -20, 20, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 20, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -20, 20, 0.1f, 0);
	controls[HEIGHT] = ModelerControl("Height", 10, 25, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

	ModelerApplication::Instance()->Init(&createGundamModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}
