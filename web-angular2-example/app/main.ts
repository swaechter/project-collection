import "core-js";
import "reflect-metadata";
import "zone.js/dist/zone";

import {provide} from "@angular/core";
import {bootstrap} from "@angular/platform-browser-dynamic";
import {LocationStrategy, HashLocationStrategy} from "@angular/common";

import {ApplicationComponent} from "./application.component";
import {APP_ROUTER_PROVIDERS} from "./application.routes";

bootstrap(ApplicationComponent, [APP_ROUTER_PROVIDERS, provide(LocationStrategy, {useClass: HashLocationStrategy})]).catch((err:any) => console.error(err));
