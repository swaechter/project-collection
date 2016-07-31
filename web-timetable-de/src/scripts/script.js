// Init page - load and display professions
function initPage()
{	
	// Hide everything
	$("#page-content").children().hide();
	
	// Load professions
	$.ajax(
	{
		url: 'http://home.gibm.ch/interfaces/133/berufe.php',
		dataType: 'json',
		success: function(data)
		{
			// Add professions
			$.each(data, function(i, item)
			{
				$('#selectprofession').append('<option value="' + item.beruf_id + '">' + item.beruf_name + '</option>');
			});
			
			// Show profession
			fadeIn('#labelprofession, #selectprofession');
			
			// Set current week
			$('#buttonweektext').text(getCurrentWeek() + '-' + getCurrentYear());
			
			// Hide timetable and bottom actions
			hideTimetableAndBottomActions();
			
			// Select profession if local storage value is valid
			var localprofession = localStorage.getItem("Profession");
			if(localprofession && localprofession.length && $("#selectprofession option[value='" + localprofession + "']").length > 0)
			{
				$('#selectprofession').val(localprofession);
				$('#selectprofession').trigger('change');
			}
		}
	});
}
$(document).ready(initPage);

// Handle the selection of a profession option
function handleProfessionSelect()
{
	// Wait for valid selection
	$('#selectprofession').change(function()
	{
		if($('#selectprofession').val() != '-') // Valid selection
		{
			// Clear timetable
			hideTimetableAndBottomActions();
			
			// Load classes
			$.ajax(
			{
				url: 'http://home.gibm.ch/interfaces/133/klassen.php',
				data: {'beruf_id' : $('#selectprofession').val()},
				dataType: 'json',
				success: function(data)
				{
					if($('#selectprofession').val() != '-') // Avoid impact of delayed AJAX reply
					{
						// Clear classes
						$('#selectclass option[value !="-"]').remove();
				
						// Add classes
						$.each(data, function(i, item)
						{
							$('#selectclass').append('<option value="' + item.klasse_id + '">' + item.klasse_name + '</option>');
						});
						
						// Show class
						fadeIn('#labelclass, #selectclass')
						
						// Select class if local storage value is valid
						var localclass = localStorage.getItem("Class");
						if(localclass && localclass.length && $("#selectclass option[value='" + localclass + "']").length > 0)
						{
							$('#selectclass').val(localclass);
							$('#selectclass').trigger('change');
						}
					}
				}
			});
		}
		else // There is no class
		{
			// Clear classes
			$('#selectclass option[value !="-"]').remove();
			
			// Hide class elements
			fadeOut('#selectclass, #labelclass');
			
			// Hide timetable and bottom actions
			hideTimetableAndBottomActions();
		}
	});
}
$(document).ready(handleProfessionSelect);

// Handle the selection of a class option
function handleClassSelect()
{
	// Wait for valid selection
	$('#selectclass').change(function()
	{
		if($('#selectclass').val() != '-') // Valid selection
		{
			var params = $('#buttonweektext').text().split('-');
			$.ajax(
			{
				url: 'http://home.gibm.ch/interfaces/133/tafel.php',
				data: {'klasse_id' : $('#selectclass').val() , 'woche' : params[0] + '-' + params[1]},
				dataType: 'json',
				success: function(data)
				{
					if($('#selectprofession').val() != '-' && $('#selectclass').val() != '-') // Avoid impact of delayed AJAX reply
					{
						// Clear timetable
						$('#timetable tbody').empty();
						
						// Add content
						if(data && data.length)
						{
							$.each(data, function(i, item)
							{
								var tr = $('<tr></tr>').appendTo($('#timetable tbody'));
								$('<td>' + dayFromNumber(item.tafel_wochentag) + '</td>').appendTo(tr);
								$('<td>' + item.tafel_von + ' - ' + item.tafel_bis + '</td>').appendTo(tr);
								$('<td>' + item.tafel_lehrer + '</td>').appendTo(tr);
								$('<td>' + item.tafel_longfach + '</td>').appendTo(tr);
								$('<td>' + item.tafel_raum + '</td>').appendTo(tr);
								$('<td>' + item.tafel_kommentar + '</td>').appendTo(tr);
							});
						}
						else // Add empty table
						{
							// Add message
							var tr = $('<tr></tr>').appendTo($('#timetable tbody'));
							$('<td>Keine Daten</td>').appendTo(tr);
							
							// Add empty fields
							for(var i = 0; i < 5; i++)
							{
								$('<td></td>').appendTo(tr);
							}
						}
						
						// Show timetable
						fadeIn('#timetable, #page-timetable');
						
						// Show bottom actions
						fadeIn('#page-bottom');
						refreshSaveButton();
						
					}
				}
			});
		}
		else // There is no timetable
		{
			// Hide timetable and bottom actions
			hideTimetableAndBottomActions();
		}
	});
}
$(document).ready(handleClassSelect);

// Handle the click of the save button
function handleSaveClick()
{
	$('#buttonsave').click(function()
	{
		if($('#buttonsaveicon').hasClass('glyphicon-floppy-disk'))
		{
			localStorage.setItem("Profession", $('#selectprofession').val());
			localStorage.setItem("Class", $('#selectclass').val());
		}
		else
		{
			localStorage.removeItem("Profession");
			localStorage.removeItem("Class");
		}
		refreshSaveButton();
	});
}
$(document).ready(handleSaveClick);

// Handle the click of the previous/next week button
function handleWeekClick()
{
	$('#buttonprevious').click(function()
	{
		var params = $('#buttonweektext').text().split('-');
		var week = params[0];
		var year = params[1];
		if(week  > 1) // Current year
		{
			week--;
		}
		else // Previous year
		{
			year--;
			week = 52;
		}
		$('#buttonweektext').text(week + '-' + year);
		$('#selectclass').trigger('change');
	});
	
	$('#buttonnext').click(function()
	{
		var params = $('#buttonweektext').text().split('-');
		var week = params[0];
		var year = params[1];
		if(week  < 52) // Current year
		{
			week++;
		}
		else // Next year
		{
			year++;
			week = 1;
		}
		$('#buttonweektext').text(week + '-' + year);
		$('#selectclass').trigger('change');
	});
}
$(document).ready(handleWeekClick);

// Clear the current timetable, hide the timetable and the bottom actions
function hideTimetableAndBottomActions()
{
	fadeOut('#page-timetable');
	fadeOut('#page-bottom');
}

// Refresh save button
function refreshSaveButton()
{
	if($('#selectprofession').val() != '-' && $('#selectclass').val() != '-')
	{
		if($('#selectprofession').val() == localStorage.getItem("Profession") && $('#selectclass').val() == localStorage.getItem("Class"))
		{
			$("#buttonsaveicon").removeClass("glyphicon-floppy-disk").addClass("glyphicon-trash");
		}
		else
		{
			$("#buttonsaveicon").removeClass("glyphicon-trash").addClass("glyphicon-floppy-disk");
		}
	}
}

// Fade in and show the object
function fadeIn(selector)
{
	$(selector).fadeIn("slow");
}

// Fade out and hide the object
function fadeOut(selector)
{
	$(selector).fadeOut("slow");
}

// Return the day from a number
function dayFromNumber(number)
{
	var days = new Array("Mo", "Di", "Mi", "Do", "Fr", "Sa", "So");
	return days[number - 1]; // 1 is monday and not 0
}

// Return the current week of this year
function getCurrentWeek()
{
	var date = new Date();
	var januar = new Date(date.getFullYear(), 0, 1);
	return Math.ceil((((date - januar) / 86400000) + januar.getDay()+ 1) / 7);
}

// Return the current year
function getCurrentYear()
{
	var date = new Date();
	return date.getFullYear();
}
