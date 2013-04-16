#include "TPinterface.h"
#include "LightingScene.h"


TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
    //CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
		case 'j':
		{
			((LightingScene *) scene)->myBot->rotateLeft();
			break;
		}
        
        case 'l':
        {
            ((LightingScene *) scene)->myBot->rotateRight();
			break;
        }
            
        case 'i':
        {
            ((LightingScene *) scene)->myBot->moveForward();
			break;
        }
            
        case 'k':
        {
            ((LightingScene *) scene)->myBot->moveBackward();
			break;
        }
	}
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);
	
	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %ld\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		};

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		};
	};
}
 

