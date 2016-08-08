package ch.swaechter.springapp.backend;

import ch.swaechter.springapp.services.Site;
import ch.swaechter.springapp.services.SiteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class TestController {

    @Autowired
    private SiteService testservice;

    @RequestMapping(value = "/")
    public List<Site> testindex() {
        return testservice.getSites();
    }
}
