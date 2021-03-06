package ee.ut.ati.masters.h2;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.sql.DataSource;

public class XmppDAO {

	public static void insertSensorData(DataSource dataSource, int location,
			int type, double value) {
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		try {
			connection = dataSource.getConnection();
			preparedStatement = connection
					.prepareStatement("insert into data (sensortype_id, location_id, value, measure_time) "
							+ "values(?, ?, ?, current_timestamp)");
			preparedStatement.setInt(1, type);
			preparedStatement.setInt(2, location);
			preparedStatement.setDouble(3, value);
			preparedStatement.execute();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			close(connection, preparedStatement);
		}
	}

	public static void insertLocation(DataSource dataSource, String location) {
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		try {
			connection = dataSource.getConnection();
			preparedStatement = connection
					.prepareStatement("insert into locations (name) values(?)");
			preparedStatement.setString(1, location);
			preparedStatement.execute();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			close(connection, preparedStatement);
		}
	}

	private static void close(Connection connection, PreparedStatement stmt) {
		try {
			if (stmt != null)
				stmt.close();
			if (connection != null)
				connection.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
