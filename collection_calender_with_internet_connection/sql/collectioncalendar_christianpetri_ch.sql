-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: mysql.collectioncalendar.christianpetri.ch
-- Erstellungszeit: 12. Nov 2018 um 01:31
-- Server-Version: 5.6.34-log
-- PHP-Version: 7.1.22

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `collectioncalendar_christianpetri_ch`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `circle`
--

CREATE TABLE `circle` (
  `circle_id` int(11) NOT NULL,
  `circle_description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Daten für Tabelle `circle`
--

INSERT INTO `circle` (`circle_id`, `circle_description`) VALUES
(1, '1'),
(2, '1a'),
(3, '1b'),
(4, '2'),
(5, '3'),
(6, '4'),
(7, '5'),
(8, '6'),
(9, '7'),
(10, '8'),
(11, '9');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `collection_calendar`
--

CREATE TABLE `collection_calendar` (
  `ID` int(11) NOT NULL,
  `collection_date` date NOT NULL,
  `garbage_type_id` int(11) NOT NULL,
  `circle_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Daten für Tabelle `collection_calendar`
--

INSERT INTO `collection_calendar` (`ID`, `collection_date`, `garbage_type_id`, `circle_id`) VALUES
(1, '2018-09-29', 2, 5),
(2, '2018-09-10', 2, 7),
(3, '2018-09-10', 2, 11),
(4, '2018-09-11', 2, 8),
(5, '2018-09-12', 2, 5),
(6, '2018-09-12', 2, 6),
(7, '2018-09-17', 5, 8),
(8, '2018-09-18', 4, 4),
(9, '2018-09-18', 4, 5),
(10, '2018-09-18', 4, 1),
(11, '2018-09-18', 4, 6),
(12, '2018-09-19', 4, 10),
(13, '2018-09-19', 4, 7),
(14, '2018-09-19', 4, 11),
(15, '2018-09-19', 4, 8),
(16, '2018-09-19', 4, 9),
(17, '2018-09-19', 5, 7),
(18, '2018-09-24', 2, 1),
(19, '2018-09-25', 2, 4),
(20, '2018-09-26', 2, 5),
(21, '2018-09-26', 2, 9),
(22, '2018-10-01', 5, 2),
(23, '2018-10-02', 5, 10),
(24, '2018-10-02', 5, 11),
(25, '2018-10-02', 5, 3),
(26, '2018-10-02', 5, 9),
(27, '2018-10-03', 5, 4),
(28, '2018-10-06', 5, 5),
(29, '2018-10-06', 5, 6),
(30, '2018-10-08', 2, 10),
(31, '2018-10-08', 2, 7),
(32, '2018-10-08', 2, 11),
(33, '2018-10-09', 2, 8),
(34, '2018-10-10', 2, 5),
(35, '2018-10-10', 2, 6),
(36, '2018-10-15', 5, 8),
(37, '2018-10-17', 5, 7),
(38, '2018-10-22', 2, 1),
(39, '2018-10-23', 2, 4),
(40, '2018-10-24', 2, 5),
(41, '2018-10-24', 2, 9),
(42, '2018-10-29', 5, 2),
(43, '2018-10-30', 5, 10),
(44, '2018-10-30', 5, 11),
(45, '2018-10-30', 5, 3),
(46, '2018-10-30', 5, 9),
(47, '2018-10-31', 5, 4),
(48, '2018-11-03', 5, 5),
(49, '2018-11-03', 5, 6),
(50, '2018-11-05', 2, 10),
(51, '2018-11-05', 2, 7),
(52, '2018-11-05', 2, 11),
(53, '2018-11-06', 2, 8),
(54, '2018-11-07', 2, 5),
(55, '2018-11-07', 2, 6),
(56, '2018-11-12', 5, 8),
(57, '2018-11-14', 5, 7),
(58, '2018-11-19', 2, 1),
(59, '2018-11-20', 2, 4),
(60, '2018-11-21', 2, 5),
(61, '2018-11-21', 2, 9),
(62, '2018-11-26', 5, 2),
(63, '2018-11-27', 5, 10),
(64, '2018-11-27', 5, 11),
(65, '2018-11-27', 5, 3),
(66, '2018-11-27', 5, 9),
(67, '2018-11-28', 5, 4),
(68, '2018-12-01', 5, 5),
(69, '2018-12-01', 5, 6),
(70, '2018-12-03', 2, 10),
(71, '2018-12-03', 2, 7),
(72, '2018-12-03', 2, 11),
(73, '2018-12-04', 2, 8),
(74, '2018-12-05', 2, 5),
(75, '2018-12-05', 2, 6),
(76, '2018-12-10', 5, 8),
(77, '2018-12-12', 5, 7),
(78, '2018-12-17', 2, 1),
(79, '2018-12-18', 2, 4),
(80, '2018-12-19', 2, 5),
(81, '2018-12-19', 2, 9),
(82, '2018-12-24', 5, 2),
(83, '2018-12-27', 5, 10),
(84, '2018-12-27', 5, 11),
(85, '2018-12-27', 5, 3),
(86, '2018-12-27', 5, 9),
(87, '2018-12-28', 5, 4),
(88, '2018-12-31', 2, 10),
(89, '2018-12-31', 2, 7),
(90, '2018-12-31', 2, 11);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `garbage_type`
--

CREATE TABLE `garbage_type` (
  `garbage_type_id` int(11) NOT NULL,
  `garbage_type_description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Daten für Tabelle `garbage_type`
--

INSERT INTO `garbage_type` (`garbage_type_id`, `garbage_type_description`) VALUES
(1, 'Gruengut'),
(2, 'Karton'),
(3, 'Kehricht und Sperrgut'),
(4, 'Metall'),
(5, 'Papier');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `circle`
--
ALTER TABLE `circle`
  ADD PRIMARY KEY (`circle_id`);

--
-- Indizes für die Tabelle `collection_calendar`
--
ALTER TABLE `collection_calendar`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `garbage_type_id` (`garbage_type_id`),
  ADD KEY `circle_id` (`circle_id`);

--
-- Indizes für die Tabelle `garbage_type`
--
ALTER TABLE `garbage_type`
  ADD PRIMARY KEY (`garbage_type_id`);

--
-- AUTO_INCREMENT für exportierte Tabellen
--

--
-- AUTO_INCREMENT für Tabelle `circle`
--
ALTER TABLE `circle`
  MODIFY `circle_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT für Tabelle `collection_calendar`
--
ALTER TABLE `collection_calendar`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=91;

--
-- AUTO_INCREMENT für Tabelle `garbage_type`
--
ALTER TABLE `garbage_type`
  MODIFY `garbage_type_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints der exportierten Tabellen
--

--
-- Constraints der Tabelle `collection_calendar`
--
ALTER TABLE `collection_calendar`
  ADD CONSTRAINT `collection_calendar_ibfk_1` FOREIGN KEY (`garbage_type_id`) REFERENCES `garbage_type` (`garbage_type_id`),
  ADD CONSTRAINT `collection_calendar_ibfk_2` FOREIGN KEY (`circle_id`) REFERENCES `circle` (`circle_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
