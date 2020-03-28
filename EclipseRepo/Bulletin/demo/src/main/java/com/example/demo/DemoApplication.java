package com.example.demo;

import javax.annotation.Resource;
import javax.sql.DataSource;

import org.apache.ibatis.session.SqlSessionFactory;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.SqlSessionTemplate;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.PropertySource;

import com.example.demo.dao.BoardDAOImpl;
import com.example.demo.model.BoardData;
import com.example.demo.service.BoardService;
import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;


@SpringBootApplication
@PropertySource("classpath:/application.properties")
@MapperScan(value={"com.example.demo.mapper"})
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}
	
	 /*
     * Set_SqlSessionFactory 
     */
	@Resource
	DataSource datasource;
	
    @Bean
    public SqlSessionFactory sqlSessionFactory() throws Exception{
        
        SqlSessionFactoryBean sessionFactory = new SqlSessionFactoryBean();

        sessionFactory.setDataSource(datasource);
        sessionFactory.setConfiguration(mybatisConfig());
        return sessionFactory.getObject();
    }
	

//	@Bean
//	@ConfigurationProperties(prefix = "spring.datasource.hikari")
//	public HikariConfig hikariConfig() {
//		return new HikariConfig();
//	}
	
	@Bean
	@ConfigurationProperties(prefix = "mybatis.configuration")
	public org.apache.ibatis.session.Configuration mybatisConfig() {
		return new org.apache.ibatis.session.Configuration();
	}

//	@Bean
//	public DataSource dataSource() {
//		return new HikariDataSource(hikariConfig());
//	}

//	@Bean
//	public SqlSessionFactory sqlSessionFactory() throws Exception {
//		SqlSessionFactoryBean factoryBean = new SqlSessionFactoryBean();
//		factoryBean.setDataSource(dataSource());
//		factoryBean.setMapperLocations(applicationContext.getResources("classpath:/mappers/**/*BoardMapper.xml"));
//		factoryBean.setConfiguration(mybatisConfig());
//		return factoryBean.getObject();
//	}

	@Bean
	public SqlSessionTemplate sqlSession() throws Exception {
		return new SqlSessionTemplate(sqlSessionFactory());
	}
	
}
