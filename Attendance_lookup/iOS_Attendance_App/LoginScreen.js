import React, { useState } from 'react';
import { View, Text, TextInput, Button } from 'react-native';
import AttendanceScreen from './AttendanceScreen';

const LoginScreen = ({ onLogin }) => {
  const [enrollmentNo, setEnrollmentNo] = useState('');
  const [dob, setDOB] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleLogin = () => {
    // Basic validation
    if (!enrollmentNo || !dob || !password) {
      setError('Please fill in all fields.');
      return;
    }

    // Simulate a server-side authentication
    if (enrollmentNo === '211B173' && dob === '31-10-2002' && password === 'Manan@746') {
      setError('');
      onLogin(enrollmentNo, dob, password);
    } else {
      setError('Invalid credentials. Please try again.');
    }
  };

  return (
    <View>
      <Text>Enrollment No:</Text>
      <TextInput
        placeholder="Enter Enrollment No"
        value={enrollmentNo}
        onChangeText={(text) => setEnrollmentNo(text)}
      />

      <Text>Date of Birth:</Text>
      <TextInput
        placeholder="Enter Date of Birth (DD-MM-YYYY)"
        value={dob}
        onChangeText={(text) => setDOB(text)}
      />

      <Text>Password:</Text>
      <TextInput
        placeholder="Enter Password"
        secureTextEntry
        value={password}
        onChangeText={(text) => setPassword(text)}
      />

      {error ? <Text style={{ color: 'red' }}>{error}</Text> : null}

      <Button title="Login" onPress={handleLogin} />
    </View>
  );
};

export default LoginScreen;
