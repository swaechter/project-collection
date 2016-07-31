<?php

require_once('functions.php');

if(isLoggedIn()) // Check if the user is logged in
{
	if(getRequest())
	{
		$request = getRequest(); // Get the request and check if it is a valid one
		if($request == 'work-add')
		{
			if(getPVar('select-project') != 0 && isPVar('workdate') && isPVar('duration') && isPVar('description'))
			{
				if(addWork(getPVar('select-project'), getPVar('workdate'), getPVar('duration'), getPVar('description')))
				{
					displaySuccessBox("Die neue Arbeit wurde erfolgreich hinzugefügt");
				}
				else
				{
					displayErrorBox("Die neue Arbeit konnte nicht hinzugefügt werden");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um eine neue Arbeit hinzufügen zu können.");
			}
		}
		else if($request == 'work-edit')
		{
			if(getPVar('select-work') != '0')
			{
				foreach(getWorks() as $work)
				{
					if(getPVar('select-work') == $work['idwork'])
					{
						$data = array('projects' => getProjects(), 'idwork' => $work['idwork'], 'workdate' => $work['workdate'], 'duration' => $work['duration'], 'description' => $work['description']);
						displayReplyPageWithData('replies/reply-work-edit-panel', $data);
					}
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie eine Arbeit aus.");
			}
		}
		else if($request == 'work-edit-panel')
		{
			if(isPVar('idwork') && getPVar('select-project') != 0 && isPVar('workdate') && isPVar('duration') && isPVar('description'))
			{
				if(editWork(getPVar('idwork'), getPVar('select-project'), getPVar('workdate'), getPVar('duration'), getPVar('description')))
				{
					displaySuccessBox("Die Arbeit konnte erfolgreich geändert werden.");
				}
				else
				{
					displayErrorBox("Die Arbeit konnte nicht geändert werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um eine bestehende Arbeit ändern zu können.");
			}
		}
		else if($request == 'work-delete')
		{
			if(getPVar('select-work') != '0')
			{
				if(deleteWork(getPVar('select-work')))
				{
					displaySuccessBox("Die Arbeit wurde erfolgreich gelöscht.");
				}
				else
				{
					displayErrorBox("Die Arbeit konnte nicht gelöscht werden.");
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie eine Arbeit aus.");
			}
		}
		else if($request == 'user-create')
		{
			if(isPVar('firstname') && isPVar('lastname') && isPVar('password1') && isPVar('password2') && getPVar('position') != 0 && isPVar('inhouseprice') && isPVar('outhouseprice') && isPVar('quota'))
			{
				if(createUser(getPVar('firstname'), getPVar('lastname'), getPVar('password1'), getPVar('password2'), getPVar('position'), getPVar('inhouseprice'), getPVar('outhouseprice'), getPVar('quota')))
				{
					displaySuccessBox("Der neue Mitarbeiter konnte erfolgreich erstellt werden.");
				}
				else
				{
					displayErrorBox("Der neue Mitarbeiter konnte nicht erstellt werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um einen neuen Mitarbeiter zu erstellen.");
			}
		}
		else if($request == 'user-edit')
		{
			if(getPVar('select-user') != '0')
			{
				foreach(getUsers() as $user)
				{
					if(getPVar('select-user') == $user['iduser'])
					{
						$data = array('iduser' => $user['iduser'], 'firstname' => $user['firstname'], 'lastname' => $user['lastname'], 'position' => $user['position'], 'inhouseprice' => $user['inhouseprice'], 'outhouseprice' => $user['outhouseprice'], 'quota' => $user['quota']);
						displayReplyPageWithData('replies/reply-user-edit', $data);
					}
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Kunden aus.");
			}
		}
		else if($request == 'user-edit-panel')
		{
			if(isPVar('iduser') && isPVar('firstname') && isPVar('lastname') && getPVar('position') != 0 && isPVar('inhouseprice') && isPVar('outhouseprice') && isPVar('quota'))
			{
				if(editUser(getPVar('iduser'), getPVar('firstname'), getPVar('lastname'), getPVar('position'), getPVar('inhouseprice'), getPVar('outhouseprice'), getPVar('quota')))
				{
					displaySuccessBox("Der Mitarbeiter konnte erfolgreich geändert werden.");
				}
				else
				{
					displayErrorBox("Der Mitarbeiter konnte nicht geändert werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um einen bestehenden Mitarbeiter ändern zu können.");
			}
		}
		else if($request == 'user-delete')
		{
			if(getPVar('select-user') != '0')
			{
				if(deleteUser(getPVar('select-user')))
				{
					displaySuccessBox("Der Mitarbeiter wurde erfolgreich gelöscht.");
				}
				else
				{
					displayErrorBox("Der Mitarbeiter konnte nicht gelöscht werden.");
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Mitarbeiter aus.");
			}
		}
		else if($request == 'customer-create')
		{
			if(isPVar('name') && isPVar('adress') && isPVar('town'))
			{
				if(createCustomer(getPVar('name'), getPVar('adress'), getPVar('townnumber'), getPVar('town')))
				{
					displaySuccessBox("Der neue Kunde konnte erfolgreich erstellt werden.");
				}
				else
				{
					displayErrorBox("Der neue Kunde konnte nicht erstellt werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um einen neuen Kunden zu erstellen.");
			}
		}
		else if($request == 'customer-edit')
		{
			if(getPVar('select-customer') != '0')
			{
				foreach(getCustomers() as $customer)
				{
					if(getPVar('select-customer') == $customer['idcustomer'])
					{
						$data = array('idcustomer' => $customer['idcustomer'], 'name' => $customer['name'], 'adress' => $customer['adress'], 'townnumber' => $customer['townnumber'], 'town' => $customer['town']);
						displayReplyPageWithData('replies/reply-customer-edit', $data);
					}
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Kunden aus.");
			}
		}
		else if($request == 'customer-edit-panel')
		{
			if(isPVar('idcustomer') && isPVar('name') && isPVar('adress') && isPVar('townnumber') && isPVar('town'))
			{
				if(editCustomer(getPVar('idcustomer'), getPVar('name'), getPVar('adress'), getPVar('townnumber'), getPVar('town')))
				{
					displaySuccessBox("Der Kunde konnte erfolgreich geändert werden.");
				}
				else
				{
					displayErrorBox("Der Kunde konnte nicht geändert werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um einen bestehenden Kunden ändern zu können.");
			}
		}
		else if($request == 'customer-delete')
		{
			if(getPVar('select-customer') != '0')
			{
				if(deleteCustomer(getPVar('select-customer')))
				{
					displaySuccessBox("Der Kunde wurde erfolgreich gelöscht.");
				}
				else
				{
					displayErrorBox("Der Kunde konnte nicht gelöscht werden.");
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Kunden aus.");
			}
		}
		else if($request == 'project-create')
		{
			if(isPVar('name') && getPVar('select-project') != 0)
			{
				if(createProject(getPVar('name'), getPVar('select-project') != 0))
				{
					displaySuccessBox("Das Projekt konnte erfolgreich erstellt werden.");
				}
				else
				{
					displayErrorBox("Das Projekt konnte nicht erstellt werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um ein neues Projekt erstellen zu können.");
			}
		}
		else if($request == 'project-edit')
		{
			if(getPVar('select-project') != '0')
			{
				foreach(getProjects() as $project)
				{
					if(getPVar('select-project') == $project['idproject'])
					{
						$data = array('idproject' => $project['idproject'], 'name' => $project['name'], 'customers' => getCustomers());
						displayReplyPageWithData('replies/reply-project-edit', $data);
					}
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie ein Projekt aus.");
			}
		}
		else if($request == 'project-edit-panel')
		{
			if(isPVar('idproject') && isPVar('name') && getPVar('select-customer') != 0)
			{
				if(editProject(getPVar('idproject'), getPVar('name'), getPVar('select-customer')))
				{
					displaySuccessBox("Das Projekt konnte erfolgreich geändert werden.");
				}
				else
				{
					displayErrorBox("Das Projekt konnte nicht geändert werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um ein bestehendes Projekt ändern zu können.");
			}
		}
		else if($request == 'project-delete')
		{
			if(getPVar('select-project') != '0')
			{
				if(deleteProject(getPVar('select-project')))
				{
					displaySuccessBox("Das Projekt wurde erfolgreich gelöscht.");
				}
				else
				{
					displayErrorBox("Das Projekt konnte nicht gelöscht werden.");
				}
			}
			else
			{
				displayErrorBox("Bitte wählen Sie ein Projekt aus.");
			}
		}
		else if($request == 'statistic-work')
		{
			if(getPVar('select-month') != 0)
			{
				$data = getWorkForIDForMonth(null, getPVar('select-month'));
				displayReplyPageWithData('replies/reply-statistic-work', $data);
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Monat aus.");
			}
		}
		else if($request == 'statistic-work-user')
		{
			if(getPVar('select-user') != 0 && getPVar('select-month') != 0)
			{
				$data = getWorkForIDForMonth(getPVar('select-user'), getPVar('select-month'));
				displayReplyPageWithData('replies/reply-statistic-work', $data);
			}
			else
			{
				displayErrorBox("Bitte wählen Sie einen Mitarbeiter/Monat aus.");
			}
		}
		else if($request == 'statistic-work-customer')
		{
			if(getPVar('select-customer') != 0 && isPVar('workdatestart') && isPVar('workdateend'))
			{
				$data = getWorkForCustomerDuringTime(getPVar('select-customer'), getPVar('workdatestart'), getPVar('workdateend'));
				displayReplyPageWithData('replies/reply-statistic-work-customer', $data);
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um die Statistik anzeigen zu können.");
			}
		}
		else if($request == 'settings')
		{
			if(isPVar('password1') && isPVar('password2'))
			{
				if(editUserPassword(getPVar('password1'), getPVar('password2')))
				{
					displaySuccessBox("Ihr Passwort wurde erfolgreich geändert.");
				}
				else
				{
					displayErrorBox("Ihr Passwort konnte nicht geändert werden.");
				}
			}
			else
			{
				displayErrorBox("Es sind nicht alle Daten vorhanden, um Ihr Passwort ändern zu können.");
			}
		}
		else // Invalid request
		{
			displayErrorBox("Ein ungültiger Request wurde gesendet.");
		}
	}
	else // Missing request parameter
	{
		displayErrorBox("Die Seite wurde nicht definiert und kann folglicherweise nicht gefunden werden.");
	}
}
else // User is not logged in - someone cannot abuse our AJAX call from an externel page
{
	displayErrorBox("Sie sind nicht angemeldet.");
}

?>
