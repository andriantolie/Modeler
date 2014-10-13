#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, ROTATE_UPPER_BODY, RAISE_RIGHT_ARM, RAISE_LEFT_ARM, ROTATE_HEAD_X, ROTATE_HEAD_Y, ROTATE_HEAD_Z, LEFT_FOREARM_ROTATION, RIGHT_FOREARM_ROTATION, LEFT_ARM_JOINT_MOVEMENT, RIGHT_ARM_JOINT_MOVEMENT, LIGHT_INTENSITY, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		1.0f, 0.65f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif