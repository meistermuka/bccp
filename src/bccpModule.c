#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <gphoto2/gphoto2-camera.h>
#include "bccpHelpers.h"

char* get_iso(Camera *camera, GPContext *context) {

	int ret;
	char *iso;

	ret = get_config_value_string(camera, "iso", &iso, context);
	if(ret >= GP_OK)
		return iso;
	else {
		free(iso);
		return NULL;
	}
}

int set_iso(Camera *camera, GPContext *context, const char *iso) {

	int ret;

	ret = set_config_value_string(camera, "iso", iso, context);
	if(ret >= GP_OK)
		return GP_OK;
	else
		return ret;

}

char* get_aperture(Camera *camera, GPContext *context) {

	int ret;
	char *aperture;

	ret = get_config_value_string(camera, "aperture", &aperture, context);
	if(ret >= GP_OK)
		return aperture;
	else {
		free(aperture);
		return NULL;
	}
}

int set_aperture(Camera *camera, GPContext *context, const char *aperture) {

	int ret;

	ret = set_config_value_string(camera, "f-stop", aperture, context);
	if(ret >= GP_OK)
		return GP_OK;
	else
		return ret;
}

char* get_shutterspeed(Camera *camera, GPContext *context) {

	int ret;
	char *shutterspeed;

	ret = get_config_value_string(camera, "shutterspeed2", &shutterspeed, context);
	if(ret >= GP_OK)
		return shutterspeed;
	else {
		free(shutterspeed);
		return NULL;
	}


}

int set_shutterspeed(Camera *camera, GPContext *context, const char *shutterspeed) {

	int ret;

	ret = set_config_value_string(camera, "shutterspeed", shutterspeed, context);
	if(ret >= GP_OK)
		return GP_OK;
	else
		return ret;

}

int menu(void) {

    CLEAR_TERM;
    int cmd = 0;

    printf("=====| BCC: Basic Camera Control |=====\n");
    printf("Choose a command:\n\n");
    printf("1) Camera Info\n");
    printf("2) GET/SET Shutter Speed\n");
    printf("3) GET/SET ISO\n");
    printf("4) GET/SET Aperture\n");
    printf("5) Capture Image\n");
    printf("0) Exit Program\n");
    printf("\n=====================================\n");

    scanf("%d", cmd);
    CLEAR_TERM;
    return cmd;

}

int main(void) {

	int ret, cmd;
	Camera *camera;
	GPContext *context;

	context = create_context();
	gp_camera_new(&camera);

	ret = gp_camera_init(camera, context);

	if(ret < GP_OK) {
		printf("No camera detected.\n");
		gp_camera_free(camera);
		return -1;
	}
    
    while(cmd!=0) {
        
        cmd = menu();

        switch(cmd) {
            case 1:
                printf("%s\n", get_camerainfo(camera, context));
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                printf("Nothing to do for now!\n");
                break;
            default:
                break;
        }
    }

	gp_camera_exit(camera, context);
	gp_camera_free(camera);
	gp_context_unref(context);

	return EXIT_SUCCESS;
}
