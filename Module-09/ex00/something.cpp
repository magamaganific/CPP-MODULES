
		if (firstLine)
			firstLine = false;
		if (line.length() < 14){
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		else if (sscanf((line.c_str()), "%d-%d-%d | %f%c", &year, &month, &day,
						&value, &extra) == 4){
			if (std::isspace(line[13]) || line[11] != '|' || line[line.length() - 1] == '.'){
				std::cout << "Error : bad input => " << line << std::endl;
				continue;
			}
			try
			{
				checkValues(value);
				checkDate(year, month, day);
			}
			catch (std::string error)
			{
				std::cout << "Error: " << error << std::endl;
				continue;
			}
		}
		else
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		size_t pos;

		pos = line.find(' ');
		LineData.date = line.substr(0, pos);
		LineData.value = value;
		findDateAndCalculate();
	}