package ch.swaechter.springapp.services;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class SiteServiceImpl implements SiteService {

    private final SessionFactory sessionfactory;

    @Autowired
    public SiteServiceImpl(SessionFactory sessionfactory) {
        this.sessionfactory = sessionfactory;

        Session session = sessionfactory.openSession();
        Transaction transaction = session.beginTransaction();

        Site site1 = new Site();
        site1.setTitle("Site 1");
        site1.setContent("This is site 1");

        Site site2 = new Site();
        site2.setTitle("Site 2");
        site2.setContent("This is site 2");

        Site site3 = new Site();
        site3.setTitle("Site 3");
        site3.setContent("This is site 3");

        session.save(site1);
        session.save(site2);
        session.save(site3);

        transaction.commit();
        session.close();
    }

    public List<Site> getSites() {
        Session session = sessionfactory.openSession();
        Transaction transaction = session.beginTransaction();
        List<Site> sites = session.createQuery("FROM Site").list();
        transaction.commit();
        session.close();
        return sites;
    }
}
