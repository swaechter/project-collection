import {Component} from "@angular/core";
import {HTTP_PROVIDERS} from "@angular/http";
import {ROUTER_DIRECTIVES} from "@angular/router";

@Component({
    selector: "webcms-application",
    providers: [HTTP_PROVIDERS],
    directives: [ROUTER_DIRECTIVES],
    template: require("./application.component.html")
})

export class ApplicationComponent {
}
