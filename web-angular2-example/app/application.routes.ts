import {provideRouter, RouterConfig} from "@angular/router";

import {HomeComponent} from "./home/home.component";
import {HelpComponent} from "./help/help.component";

export const routes:RouterConfig = [
    {path: "", redirectTo: "/home", pathMatch: "full"},
    {path: "home", component: HomeComponent},
    {path: "help", component: HelpComponent}
];

export const APP_ROUTER_PROVIDERS = [provideRouter(routes)];
