#include <zephyr/logging/log.h>

#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_CENTRAL)
#include "central_widgets/label_layer_status.h"
#include "central_widgets/kb_status.h"
#include "central_widgets/bongo_cat.h"
#endif

#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_SUBORDINATE)
#include "subordinate_widgets/image.h"
#include "subordinate_widgets/battery.h"
#endif

#include "custom_status_screen.h"


LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);


#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_CENTRAL)
static struct zmk_widget_label_layer_status widget_label_layer_status;
static struct zmk_widget_kb_status widget_kb_status;
static struct zmk_widget_bongo_cat widget_bongo_cat;
#endif

#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_SUBORDINATE)
static struct zmk_widget_image widget_image;
static struct zmk_widget_battery widget_battery;
#endif

lv_style_t global_style;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_CENTRAL)
	zmk_widget_label_layer_status_init(&widget_label_layer_status, screen);
    zmk_widget_bongo_cat_init(&widget_bongo_cat, screen);
	zmk_widget_kb_status_init(&widget_kb_status, screen);

	lv_obj_align(zmk_widget_label_layer_status_obj(&widget_label_layer_status), LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_align(zmk_widget_bongo_cat_obj(&widget_bongo_cat), LV_ALIGN_TOP_LEFT, 22, 0);
	lv_obj_align(zmk_widget_kb_status_obj(&widget_kb_status), LV_ALIGN_TOP_LEFT, -10, 0);
#endif

#if IS_ENABLED(CONFIG_CORNE_WIDGET_STATUS_SUBORDINATE)
	zmk_widget_image_init(&widget_image, screen);
	zmk_widget_battery_init(&widget_battery, screen);

	lv_obj_align(zmk_widget_image_obj(&widget_image), LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_align(zmk_widget_battery_obj(&widget_battery), LV_ALIGN_TOP_LEFT, -10, 0);
#endif
    return screen;
}
