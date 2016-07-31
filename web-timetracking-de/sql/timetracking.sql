SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `timetracking` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
USE `timetracking` ;

-- -----------------------------------------------------
-- Table `timetracking`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `timetracking`.`user` ;

CREATE TABLE IF NOT EXISTS `timetracking`.`user` (
  `iduser` INT NOT NULL AUTO_INCREMENT,
  `firstname` VARCHAR(100) NOT NULL,
  `lastname` VARCHAR(100) NOT NULL,
  `password` VARCHAR(128) NOT NULL,
  `position` INT NOT NULL,
  `inhouseprice` INT NOT NULL,
  `outhouseprice` INT NOT NULL,
  `quota` DOUBLE NOT NULL,
  PRIMARY KEY (`iduser`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;


-- -----------------------------------------------------
-- Table `timetracking`.`customer`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `timetracking`.`customer` ;

CREATE TABLE IF NOT EXISTS `timetracking`.`customer` (
  `idcustomer` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(100) NOT NULL,
  `adress` VARCHAR(100) NOT NULL,
  `townnumber` INT NOT NULL,
  `town` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`idcustomer`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;


-- -----------------------------------------------------
-- Table `timetracking`.`project`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `timetracking`.`project` ;

CREATE TABLE IF NOT EXISTS `timetracking`.`project` (
  `idproject` INT NOT NULL AUTO_INCREMENT,
  `customer_idcustomer` INT NOT NULL,
  `name` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`idproject`),
  INDEX `fk_project_customer1_idx` (`customer_idcustomer` ASC),
  CONSTRAINT `fk_project_customer1`
    FOREIGN KEY (`customer_idcustomer`)
    REFERENCES `timetracking`.`customer` (`idcustomer`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;


-- -----------------------------------------------------
-- Table `timetracking`.`work`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `timetracking`.`work` ;

CREATE TABLE IF NOT EXISTS `timetracking`.`work` (
  `idwork` INT NOT NULL AUTO_INCREMENT,
  `user_iduser` INT NOT NULL,
  `project_idproject` INT NOT NULL,
  `workdate` DATE NOT NULL,
  `duration` INT NOT NULL,
  `description` VARCHAR(1000) NOT NULL,
  INDEX `fk_user_has_project_project1_idx` (`project_idproject` ASC),
  INDEX `fk_user_has_project_user_idx` (`user_iduser` ASC),
  PRIMARY KEY (`idwork`),
  CONSTRAINT `fk_user_has_project_user`
    FOREIGN KEY (`user_iduser`)
    REFERENCES `timetracking`.`user` (`iduser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_user_has_project_project1`
    FOREIGN KEY (`project_idproject`)
    REFERENCES `timetracking`.`project` (`idproject`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
