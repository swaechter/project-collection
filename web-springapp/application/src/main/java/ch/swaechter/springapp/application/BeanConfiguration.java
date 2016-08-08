package ch.swaechter.springapp.application;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.orm.jpa.vendor.HibernateJpaSessionFactoryBean;

@Configuration
public class BeanConfiguration {

    @Bean
    public HibernateJpaSessionFactoryBean getSessionFactory() {
        return new HibernateJpaSessionFactoryBean();
    }
}
