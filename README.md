<h2>Steps to Setup this project</h2>
NodeMcu(ESP8266) - <a href="http://arduino.esp8266.com/stable/package_esp8266com_index.json">http://arduino.esp8266.com/stable/package_esp8266com_index.json</a><br>Go to <b>File </b>><b>Preferences</b> and paste this link
<br>Now Go to <b>Tools</b>><b>Board</b> and Select <b>NodeMCU 1.0 (ESP-12E Module)</b>
<br>Create New Sketch File and Paste the code given in <a href="https://github.com/ManglamX/ProjectCellRemote/blob/main/EspCode/pcell.ino">pcell.ino</a>
<br>
<h2>Pin Connection</h2>
<table border="1">
  <tr>
    <th>Relay Module Pin</th>
    <th>NodeMCU (ESP8266) Pin</th>
  </tr>
  <tr>
    <td>VCC</td>
    <td>Vin</td>
  </tr>
  <tr>
    <td>GND</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>Relay 1</td>
    <td>D1 (GPIO5)</td>
  </tr>
  <tr>
    <td>Relay 2</td>
    <td>D2 (GPIO4)</td>
  </tr>
  <tr>
    <td>Relay 3</td>
    <td>D3 (GPIO0)</td>
  </tr>
  <tr>
    <td>Relay 4</td>
    <td>D4 (GPIO2)</td>
  </tr>
  <tr>
    <td>Relay 5</td>
    <td>D5 (GPIO14)</td>
  </tr>
  <tr>
    <td>Relay 6</td>
    <td>D6 (GPIO12)</td>
  </tr>
  <tr>
    <td>Relay 7</td>
    <td>D7 (GPIO13)</td>
  </tr>
  <tr>
    <td>Relay 8</td>
    <td>D8 (GPIO15)</td>
  </tr>
</table>
