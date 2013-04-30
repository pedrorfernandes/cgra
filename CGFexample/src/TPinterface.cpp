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
	//GLUI_Panel *varPanel= addPanel((char*)"Group", 1);
	//addSpinnerToPanel(varPanel, (char*)"Val 1(interface)", 2, &testVar, 1);
	
	// You could also pass a reference to a variable from the scene class, if public
	//addSpinnerToPanel(varPanel, (char*)"Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);
    
    GLUI_Panel * lightsPanel = addPanel( (char*)"Luzes", 1);
    
    addCheckboxToPanel(lightsPanel, (char*)"Luz 1", &(((LightingScene*) scene)->light0On), 0);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 2", &(((LightingScene*) scene)->light1On), 1);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 3", &(((LightingScene*) scene)->light2On), 2);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 4", &(((LightingScene*) scene)->light3On), 3);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 5", &(((LightingScene*) scene)->light4On), 4);
    
    addButton((char*)"Parar/continuar relogio", 5);
        
    GLUI_Panel * texturePanel = addPanel( (char*)"Textura do Robot");
    
    GLUI_Listbox * textureList = addListboxToPanel(texturePanel, (char*)"Escolha", &(((LightingScene*) scene)->myBot->texture), 6);
    
    textureList->add_item (0, "Nenhuma");
    textureList->add_item (1, "Android");
    textureList->add_item (2, "Metal");
    textureList->add_item (3, "Predefinida");
    textureList->add_item (4, "Matrix");
    
    textureList->set_int_val (1);
    
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %ld\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
        case 0:
        {
            // value is the contrary because it has been switched already
            if ( !((LightingScene*) scene)->light0On ){
                ((LightingScene*) scene)->light0->disable();
            } else {
                ((LightingScene*) scene)->light0->enable();
            }
            break;
        }
		case 1:
		{
			if ( !((LightingScene*) scene)->light1On ){
                ((LightingScene*) scene)->light1->disable();
            } else {
                ((LightingScene*) scene)->light1->enable();
            }
            break;
		}
		case 2:
		{
			if ( !((LightingScene*) scene)->light2On ){
                ((LightingScene*) scene)->light2->disable();
            } else {
                ((LightingScene*) scene)->light2->enable();
            }
            break;
		}
        case 3:
        {
            if ( !((LightingScene*) scene)->light3On ){
                ((LightingScene*) scene)->light3->disable();
            } else {
                ((LightingScene*) scene)->light3->enable();
            }
            break;
        }
        case 4:
        {
            if ( !((LightingScene*) scene)->light4On ){
                ((LightingScene*) scene)->light4->disable();
            } else {
                ((LightingScene*) scene)->light4->enable();
            }
            break;
        }
        case 5:
        {
            ((LightingScene*) scene)->clockStop = !((LightingScene*) scene)->clockStop;
            break;
        }
            
	};
}


