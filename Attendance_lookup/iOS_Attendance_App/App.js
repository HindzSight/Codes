import React, { useState } from 'react';
import { View, StyleSheet, Text } from 'react-native';
import LoginScreen from './LoginScreen';
import AttendanceScreen from './AttendanceScreen';

const App = () => {
  const [isLoggedIn, setLoggedIn] = useState(false);
  const [enrollmentNo, setEnrollmentNo] = useState('');
  const [dob, setDOB] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleLogin = (enrollmentNo, dob, password) => {
    // Basic validation
    if (!enrollmentNo || !dob || !password) {
      setError('Please fill in all fields.');
      return;
    }

    // Simulate a server-side authentication
    if (enrollmentNo === '211B173' && dob === '31-10-2002' && password === 'Manan@746') {
      setError('');
      setLoggedIn(true);
      setEnrollmentNo(enrollmentNo);
      setDOB(dob);
      setPassword(password);
    } else {
      setError('Invalid credentials. Please try again.');
    }
  };

  return (
    <View style={styles.container}>
      {isLoggedIn ? (
        <AttendanceScreen enrollmentNo={enrollmentNo} dob={dob} password={password} />
      ) : (
        <View style={styles.loginContainer}>
          <LoginScreen onLogin={handleLogin} />
          {error ? <Text style={styles.errorText}>{error}</Text> : null}
        </View>
      )}
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  loginContainer: {
    width: '80%',
  },
  errorText: {
    color: 'red',
    marginTop: 10,
  },
});

export default App;
