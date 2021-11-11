USE students;


SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `students`
--

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `id` int(11) NOT NULL,
  `name` varchar(400) NOT NULL,
  `semester` varchar(55) NOT NULL,
  `instructor` varchar(55) NOT NULL,
  `classroom` varchar(55) NOT NULL,
  `time` varchar(55) NOT NULL,
  `availability` varchar(55) NOT NULL DEFAULT 'available'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`id`, `name`, `semester`, `instructor`, `classroom`, `time`, `availability`) VALUES
(1, 'Python Online class', '1st', 'Jerome Goddard', '205', '12:30-1:30', 'available'),
(2, 'Python Progruming', '1st', 'Paterick Pape', '206', '12:30-1:30', 'available'),
(3, 'PHP learning', '2nd', 'Zimin Gao', '207', '1:30-2:30', 'available'),
(4, 'HTML learning', '2nd', 'Jessica vai', '207', '1:30-2:30', 'available'),
(5, 'HTML learning', '2nd', 'Jessica vai', '207', '2:30-3:30', 'available'),
(6, 'HTML learning', '2nd', 'Jessica vai', '207', '3:30-4:30', 'available'),
(7, 'HTML learning', '2nd', 'Jessica vai', '207', '4:30-5:30', 'available');

-- --------------------------------------------------------

--
-- Table structure for table `enrolled`
--

CREATE TABLE `enrolled` (
  `id` int(11) NOT NULL,
  `courseid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `date` date NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `enrolled`
--

INSERT INTO `enrolled` (`id`, `courseid`, `userid`, `date`) VALUES
(7, 1, 13, '2020-11-27'),
(9, 2, 13, '2020-11-27'),
(10, 4, 13, '2020-11-27');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `birthday` date DEFAULT NULL,
  `gender` varchar(55) NOT NULL,
  `password` varchar(255) NOT NULL,
  `auth` varchar(255) NOT NULL,
  `verify` int(11) NOT NULL DEFAULT 0,
  `course` varchar(400) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `email`, `birthday`, `gender`, `password`, `auth`, `verify`, `course`) VALUES
(1, 'test', '', '2020-11-26', '', 'test12123', '', 0, ''),
(13, 'Azad', 'azadulislam202020@gmail.com', '2020-11-03', 'male', 'a57643a1dfbcb835b6f7a0cffef1f46e', '8197523fec7bec5b422d1b301451a8d9', 1, '1,2,3,4');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `enrolled`
--
ALTER TABLE `enrolled`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `email` (`email`),
  ADD UNIQUE KEY `UNIQUE` (`username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `course`
--
ALTER TABLE `course`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `enrolled`
--
ALTER TABLE `enrolled`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
