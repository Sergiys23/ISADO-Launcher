#include "apps.h"

#include "app_manager.h"

#include "terminal/terminal.h"
#include "browser/browser.h"
#include "explorer/explorer.h"
#include "settings/settings.h"

static ISADO_App terminal =
{
    "Terminal",

    0,

    terminal_init,
    terminal_update,
    terminal_render,
    terminal_event,
    terminal_shutdown
};

static ISADO_App browser =
{
    "Browser",

    0,

    browser_init,
    browser_update,
    browser_render,
    browser_event,
    browser_shutdown
};

static ISADO_App explorer =
{
    "Explorer",

    0,

    explorer_init,
    explorer_update,
    explorer_render,
    explorer_event,
    explorer_shutdown
};

static ISADO_App settings =
{
    "Settings",

    0,

    settings_init,
    settings_update,
    settings_render,
    settings_event,
    settings_shutdown
};

void apps_init(void)
{
    app_manager_register(&terminal);

    app_manager_register(&browser);

    app_manager_register(&explorer);

    app_manager_register(&settings);

    app_manager_start("Explorer");

    app_manager_start("Terminal");
}